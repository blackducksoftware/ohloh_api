#ifndef __TCP_SOCKET_H__
#define __TCP_SOCKET_H__


#include <string>

class TCPSocket
{
 public:
 	TCPSocket(void);
 	~TCPSocket(void);
 	
 	void connect(const std::string &server, const int &port);
 	void disconnect(void);
 	bool connected(void) { return mSocket; }
 	
 	void send(const std::string &msg);
 	int recieve(std::string &ret);
 	bool eof(void) { return mEOF; }
 	
 protected: 
 	int mSocket;
 	bool mEOF;
};

#endif
