#include "Communicator.h"

//REDO EVERYTHING

void Communicator::startThreadForNewClient()
{

}

void Communicator::bindAndListen()
{
	while (true)
	{
		//Declaring the socket
		_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		struct sockaddr_in sa = { 0 };
		sa.sin_port = htons(PORT);
		sa.sin_family = AF_INET;
		sa.sin_addr.s_addr = IFACE;

		if (bind(_sock, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
			throw exception("Error in bind function");

		if (listen(_sock, SOMAXCONN) == SOCKET_ERROR)
			throw exception("Error in listen function");

		handleRequests();
	}
}

void Communicator::handleRequests()
{
	//inerting a new entry to the map



}
