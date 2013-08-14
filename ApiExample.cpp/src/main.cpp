/*



*/

/*
  MD5 algorithm implementation
  RSA Data Security, Inc. MD5 Message-Digest
  Algorithm

  For more details please consult md5.c
*/
#include "main.h"
#include "HTTPDownload.h"
#include "md5.h"
#include "tinyxml.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, const char * argv[])
{
  std::cout << std::endl << "Initializing.." << std::endl;
#ifdef OS_WINDOWS
  WSADATA data;
  WSAStartup(MAKEWORD(1, 1), &data);
#endif
  HTTPDownload * download = new HTTPDownload();

  std::pair<std::string, std::string> infoPair = parseCommandLine(argc, argv);

  if (infoPair.first.empty() || infoPair.second.empty())
  {
    return 1;
  }

  std::cout << "Forming request.." << std::endl;
  

  std::istringstream str(infoPair.second);
  MD5 md5(str);

  std::string urlString = "http://www.ohloh.net/accounts/";
  urlString += md5.hex_digest();
  urlString += ".xml?api_key=" + infoPair.first + "&v=1";

  if (download->start(urlString))
  {
    parseAndShowResult();
  }

  std::cout << std::endl << "Press the return key to exit." << std::endl;
  std::cin.get();
  return 1;
}

std::pair<std::string, std::string> parseCommandLine(int argc, const char * argv[])
{
  if (argc == 3)
  {
    return std::pair<std::string, std::string>(argv[1], argv[2]);
  }
  else
  {
    std::cout << "Usage:" << std::endl;
#ifdef OS_WINDOWS
    std::cout << "ApiExample.exe [api_key] [user_email]" << std::endl;
#else
    std::cout << "./ApiExample [api_key] [user_email]" << std::endl;
#endif
  }

  return std::pair<std::string, std::string>("", "");
}

void parseAndShowResult()
{
  std::cout << "Parsing file." << std::endl;
  TiXmlDocument doc("temp.xml");
  doc.LoadFile();
  TiXmlHandle docHandle(&doc);

  TiXmlElement * firstElements = docHandle.FirstChild("response").ToElement();



  TiXmlElement * statusElem = 0;
  statusElem = firstElements->FirstChildElement();

  if (!statusElem)
  {
    std::cout << "Corrupt file, wrong request made?" << std::endl;
    return;
  }

  if (std::string(statusElem->GetText()).compare("success") != 0)
  {
    TiXmlElement * errorElem = firstElements->FirstChildElement("error");

    std::cout << "Parsing failed with message: " << errorElem->GetText() << std::endl;
    return;
  }

  TiXmlElement * accountElement = firstElements->FirstChild("result")->FirstChild("account")->ToElement();

  TiXmlElement * nameElement = 0;
  nameElement = accountElement->FirstChildElement("name");

  if (nameElement == 0)
  {
    std::cout << "Parsing failed, could not find 'name' element." << std::endl;
    return;
  }

  std::cout << "Located name: " << nameElement->GetText() << std::endl;;  
}


