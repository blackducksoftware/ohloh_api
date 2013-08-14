#ifndef __MAIN_H__
#define __MAIN_H__

#if defined( __WIN32__ ) || defined( _WIN32 )
#   define OS_WINDOWS
#   include <winsock.h>
#else
#   define OS_LINUX
#   include <unistd.h>
#   include <errno.h>
#   include <sys/types.h>
#   include <sys/socket.h>
#   include <sys/time.h>
#   include <netinet/in.h>
#   include <arpa/inet.h>
#   include <netdb.h>
#   include <fcntl.h>
#endif

#include <string>
#include <stdio.h>


std::pair<std::string, std::string> parseCommandLine(int argc, const char * argv[]);
void parseAndShowResult();

#endif

