#pragma once

#include "Types.h"



// seperate windows includes from linux
// TODO MSK check if this works
#if defined(win32) || defined(win64)
	
	//TODO MSK change this into linux elif defined(linux_whatever)
#elif defined(__linux__)
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netdb.h>
#endif



namespace Network
{
	class Server
	{
	private:
		uint16 port;
		addrinfo serverInfo;
		sockaddr_storage clientInfo;
	public:
	Server(uint16 port);
	~Server();
	};

	class Client
	{
	Client(uint16 port);
	~Client();
	};

}
