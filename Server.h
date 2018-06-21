#pragma once

#include <thread>
#include <iostream>

#include "Communicator.h"
#include "RequestHandlerFactory.h"
#include "IDatabase.h"

class Server
{
private:
	IDatabase m_database;
	Communicator m_communicator;
	//RequestHandlerFactory m_handleFactory;

public:
	Server();

	void run();
};
