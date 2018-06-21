#include "Server.h"


Server::Server()
{
	m_communicator = Communicator();
	m_database = IDatabase();
}

void Server::run()
{
	//new thread accept new client -> handle requests + detach
	thread acceptNewClients(m_communicator.handleRequests);
	acceptNewClients.detach();

	//endless loop -> the server is free to accept requests from user
	string request;
	while (request != "exit")
	{
		getline(std::cin, request);
	}
}
