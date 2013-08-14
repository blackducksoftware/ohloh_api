#ifndef __HTTPDOWNLOAD_H__
#define __HTTPDOWNLOAD_H__

#include "TCPSocket.h"

#include <fstream>
#include <string>

class HTTPDownload
{
 public:
 	HTTPDownload(void) { }
 	virtual ~HTTPDownload(void) { }
 	
 	bool start(const std::string &url);
 	void stop(void);
 	
 protected:
 	bool _parseHeader(const std::string &header);
 	bool _download(const std::string &url);
 
 	TCPSocket		*mSocket;
 	std::ofstream 	mFile; 	
};

#endif
