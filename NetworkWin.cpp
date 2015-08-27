#include "Network.h"

namespace Internal
{
	WORD requiredNetworkVersion = MAKEWORD(2, 0);
	WSADATA networkInfo = {};

	
	void initNetwork(uint16 port)
	{
		int retval = WSAStartup(requiredNetworkVersion, &networkInfo);
		if(retval == 0)
		{
			
		}
		else 
		{
			std::cout << "initializing Network fails
		}

	}

	void destNetwork()
	{
	}

}

Network::Server::Server(uint16 port)
{
	Internal::initNetwork(port);
}

Network::Server::~Server()
{

}

Network::Client::Client(uint16 port)
{

}

Network::Client::~Client()
{

}

