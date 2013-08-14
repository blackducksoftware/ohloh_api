#include "TCPSocket.h"
#include "main.h"


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
