#pragma once

#include <map>
#include <WinSock2.h>

#include "IRequsetHandler.h"
#include "RequestHandlerFactory.h"

#include "RequestHandlerFactory.h"

using namespace std;

// using static const instead of macros 
static const unsigned short PORT = 1111; //Random port, choose another later
static const unsigned int IFACE = 0;

class Communicator
{
private:
	map<SOCKET, IRequsetHandler> m_clients;
	RequestHandlerFactory m_handlerFactory;

	//Addition
	SOCKET _sock;

	void startThreadForNewClient();

public:
	void bindAndListen();
	void handleRequests();
};
