/*
The MIT License (MIT)

Copyright (c) 2013 Lars Wesselius

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "HTTPDownload.h"

#include <iostream>
#include <sstream>
#include <map>

#define HTTP_RESPONSE_MAX_SIZE 65536

/* HTTP/1.0 status codes from RFC1945, provided for reference.  */
/* Successful 2xx.  */
#define HTTP_STATUS_OK                    200
#define HTTP_STATUS_CREATED               201
#define HTTP_STATUS_ACCEPTED              202
#define HTTP_STATUS_NO_CONTENT            204
#define HTTP_STATUS_PARTIAL_CONTENTS      206

/* Redirection 3xx.  */
#define HTTP_STATUS_MULTIPLE_CHOICES      300
#define HTTP_STATUS_MOVED_PERMANENTLY     301
#define HTTP_STATUS_MOVED_TEMPORARILY     302
#define HTTP_STATUS_SEE_OTHER             303 /* from HTTP/1.1 */
#define HTTP_STATUS_NOT_MODIFIED          304
#define HTTP_STATUS_TEMPORARY_REDIRECT    307 /* from HTTP/1.1 */

/* Client error 4xx.  */
#define HTTP_STATUS_BAD_REQUEST           400
#define HTTP_STATUS_UNAUTHORIZED          401
#define HTTP_STATUS_FORBIDDEN             403
#define HTTP_STATUS_NOT_FOUND             404
#define HTTP_STATUS_RANGE_NOT_SATISFIABLE 416

/* Server errors 5xx.  */
#define HTTP_STATUS_INTERNAL              500
#define HTTP_STATUS_NOT_IMPLEMENTED       501
#define HTTP_STATUS_BAD_GATEWAY           502
#define HTTP_STATUS_UNAVAILABLE           503

bool HTTPDownload::start(const std::string &url)
{	
		mSocket = new TCPSocket();
		return _download(url);
}

void HTTPDownload::stop()
{
	delete mSocket;
	mSocket = 0;	
}

bool HTTPDownload::_parseHeader(const std::string &header)
{
	std::string line = header.substr(0, header.find_first_of('\n'));
	size_t index = 0, size = line.size();

/* Check the HTTP of the header */	
	if (line.compare(0,4, "HTTP") != 0)
		return false;
	index = 4;
	
/* Check for the HTTP version of the header (it may not exist so skip it if its not there)*/
	if (index < size && line[index] == '/')
	{
		++index;
		while (index < size && isdigit(line[index]))
			index++;
		if (index < size && line[index] == '.')
			index++;
		while (index < size && isdigit(line[index]))
			index++;
	}	
	if (index < size && line[index] != ' ')
		return false;
	++index;
	
/* Get the status code */
	if (size - index < 3)
		return false;
	int status = atoi(line.substr(index, 3).c_str()); 
	index += 3;
	while (index < size && line[index] == ' ')
		++index;
	std::string message = line.substr(index);
	
/* Parse the status code */
	switch (status)
	{
		case HTTP_STATUS_BAD_REQUEST:
		case HTTP_STATUS_UNAUTHORIZED:
		case HTTP_STATUS_FORBIDDEN:
		case HTTP_STATUS_NOT_FOUND:
		case HTTP_STATUS_INTERNAL:
		case HTTP_STATUS_NOT_IMPLEMENTED:
		case HTTP_STATUS_BAD_GATEWAY:		
		case HTTP_STATUS_UNAVAILABLE:
                  return false;
	}
	
	std::string rest = header;	
	index = rest.find_first_of('\r');
	std::map<std::string, std::string> settings;
	while (index != std::string::npos)
	{
		rest = rest.substr(index);
		if (rest[0] == '\n' && rest[1] == '\r' && rest[2] == '\n')
			break;
			
		std::string line = rest.substr(0,rest.find('\r',1));
		while (line[0] == '\n' || line[0] == '\r' || line[0] == ' ' || line[0] == '\t')
			line = line.substr(1);		
		size_t sep = line.find_first_of(':');
		if (sep != std::string::npos)
		{
			std::string value = line.substr(sep+1);
			while (value[0] == ' ')
				value = value.substr(1);
			settings.insert(std::make_pair(line.substr(0,sep), value));		
		}
		index = rest.find('\r', 1);
	}
	if (((status > 299 && status < 308) && settings.find("Location") != settings.end()) || settings.find("Location") != settings.end())
	{
		std::cerr << "[Downloader] Download location has changed to " << settings["Location"] << "\n";
		mFile.close();
		_download(settings["Location"]);
		return false;
	}
	
	return true;
}

bool HTTPDownload::_download(const std::string &url)
{
	std::string location;
	std::cout << url << std::endl;
	
/* Check for correct url type and strip it */		
	if (url.compare(0,7,"http://") != 0)	
	{
		if (url.find("://") != std::string::npos)
			return false;
		location = url;
	}
	else
	{		
		location = url.substr(7);
	}
	
/* Get the server and the location of the file */
	std::string::size_type index = location.find_first_of('/');
	std::string::size_type dp = location.find_first_of(':');

        int port = 80;
	if (dp != std::string::npos && dp < index)
	{
                port = atoi(location.substr(dp+1, index).c_str());
		location = location.erase(dp, index-dp);
		index = dp;
	}
	
        std::string server = "";
        std::string fileLocation = "";
        std::string name = "";
        if (index == std::string::npos)
        {
          server = location;
          fileLocation = "";
        }
        else
        {
          server = location.substr(0,index);
          name = location.substr(location.find_last_of('/')+1);
          fileLocation = location.substr(index+1);
        }

        /* Do some error checking and force std names/locations */
        if (server.empty())
        {
          server = fileLocation;
          fileLocation = "";
        }
        if (name.empty())
          name = "index.html";
	
        mSocket->connect(server, port);

        if (mSocket->connected())
        {
          std::cout << "Connected." << std::endl;
        }
        else
        {
          std::cout << "Not connected." << std::endl;
        }
    	
        std::cout << "Requesting file.." << std::endl;
/* Send header .. */
    std::stringstream header;
    header << "GET /" << fileLocation << " HTTP/1.1\r\n";
    header << "Host: " << server << "\r\n";
    header << "Connection: Close\r\n";
    header << "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\n";
    header << "User-Agent: Downloader 0.1 (i686; X11; Linux)\r\n\r\n";
    
	mSocket->send(header.str());
	
    
    std::string buf, httpheader;    
/* Recieve the first packet with the http header */
    mSocket->recieve(buf);

    
/* Extract the REAL http header out of all the data */
	short i = 0;
	while (!(buf[i] == '\r' && buf[i+1] == '\n' && buf[i+2] == '\r' && buf[i+3] == '\n'))
		++i;
	
/* Parse the http header */
    if (!_parseHeader(buf.substr(0,i)))    
    {
      std::cout << buf.substr(0, i) << std::endl;
      std::cout << "Request failed. Invalid api key?" << std::endl;
    	return false;
    }

    	
/* Open the file which we're going to download */
    mFile.open("temp.xml", std::ios::trunc);
    mFile << buf.substr(i+4);      
    
    short ret;

/* Get the rest of the data */
    while (!mSocket->eof())
    {
    	//std::cerr << buf;
    	ret = mSocket->recieve(buf);
    	mFile << buf;
        mFile.flush();
    }
    mFile.close();

    std::cout << "Request completed." << std::endl;
    mSocket->disconnect();
    return true;
}
