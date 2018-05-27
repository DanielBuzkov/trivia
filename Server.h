#pragma once

#include "Communicator.h"
#include "RequestHandlerFactory.h"
#incldue "IDatabase.h"

class Server
{
private:
	IDatabase m_database;
	Communicator m_communicator;
	RequestHandlerFactory m_handleFactory;

public:
	void run();
};
