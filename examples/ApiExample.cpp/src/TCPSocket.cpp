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

#include "TCPSocket.h"
#include "main.h"
#include <cstring>


#define RESPONSE_MAX_SIZE 65536

TCPSocket::TCPSocket()
{
	mSocket = 0;
	mEOF = false;
}

TCPSocket::~TCPSocket()
{
	
}

void TCPSocket::connect(const std::string &server, const int &port)
{
	struct hostent *he;				// Host to connect to
    struct sockaddr_in server_addr;	// Address of the server
    
    if ((he = gethostbyname(server.c_str())) == NULL)
    	return;
    	
    if ((mSocket = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    	return;
    	
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(server_addr.sin_zero, '\0', sizeof server_addr.sin_zero);
    
    if (::connect(mSocket,(struct sockaddr *)&server_addr, sizeof server_addr) == -1)
    	return;
}

void TCPSocket::disconnect()
{
#ifdef OS_WINDOWS
        closesocket(mSocket);
#else
        close(mSocket);
#endif
	mSocket = 0;
	mEOF = false;
}

void TCPSocket::send(const std::string &msg)
{
	int sended = 0;
        size_t tosend = msg.size();
	while (sended < tosend)
	{
		int n;
		if ((n = ::send(mSocket, msg.substr(sended).c_str(), tosend-sended, 0)) == -1)
		{
			mEOF = true;
			return;
		}
		sended += n;
	}
}

int TCPSocket::recieve(std::string &ret)
{
	char buffer[RESPONSE_MAX_SIZE];
	int retv;
	if ((retv = recv(mSocket, buffer, RESPONSE_MAX_SIZE, 0)) == -1)
	{
		mEOF = true;
                return 0;
	}
	if (retv == 0)
		mEOF = true;
    ret = std::string(buffer, retv);
    return retv;
}
