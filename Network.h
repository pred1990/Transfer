#pragma once


//TODO MSK needs to be removed
#include <iostream> 

#include "Types.h"



// seperate windows includes from linux
// TODO MSK check if this works
#if defined(__WIN32__) || defined(__WIN64__)
	#include <winsock2.h>
	#include <windef.h>
	#include <windef.h>
	#include <Ws2tcpip.h>
	#include <stdio.h>
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
