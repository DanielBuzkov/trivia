#include "Communicator.h"

//bindAndListen:
//	bind to int?
//
//handleRequests:
//	pair<SOCEKT, IRequestHandler
//	DONE : thread param

Communicator::Communicator()
{
	bindAndListen();
}

void Communicator::bindAndListen()
{
	//Declaring the socket
	_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	sockaddr_in sa;
	memset(&sa, 0, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = IFACE;
	sa.sin_port = htons(PORT);

	if (bind(_sock, (SOCKADDR*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw exception("Error in bind function");

	if (listen(_sock, SOMAXCONN) == SOCKET_ERROR)
		throw exception("Error in listen function");

}

void Communicator::startThreadForNewClient(SOCKET s)
{
	while (true)
	{
		char messageCode[1];
		recv(s, messageCode, 1, 0);

		char messageLen[4];
		recv(s, messageLen, 4, 0);

		char message[MAX_MESSAGE_LEN];
		//3 -> 0 or 0 -> 3?
		int messageLenInt = messageLen[3];
		messageLenInt = (messageLenInt << 8) + messageLen[2];
		messageLenInt = (messageLenInt << 8) + messageLen[1];
		messageLenInt = (messageLenInt << 8) + messageLen[0];

		recv(s, message, messageLenInt, 0);

		struct Request r;

		for (int i = 0; i < messageLenInt; i++)
			r.buffer.push_back((uint8_t)message[i]);

		r.id = (int)messageCode;
		r.receivalTime = time(NULL);

		RequestResult newResult = m_clients.at(s).handleRequest(r);
		vector<uint8_t> res = newResult.Response;

		char* test = new char[res.size()];
		std::copy(res.begin(), res.end(), test);

		send(s, test, sizeof(test), 0);
	}
		//listen to client
		//read byte (recieve) - message code
		//read 4 byted for len
		//read len byte
		//request struct -> put message code + message (JSON)
		//isRequestRelevant - is the message code is a known code?
}

void Communicator::handleRequests()
{
	SOCKET acceptSocket;

	while (true)
	{
		acceptSocket = accept(_sock, NULL, NULL);

		if (acceptSocket != INVALID_SOCKET) 
		{
			IRequsetHandler* handler = &RequestHandlerFactory::createLoginRequestHandler();
			m_clients.insert(pair<SOCKET, IRequsetHandler>(acceptSocket, *handler));
			//map<SOCKET, IRequsetHandler> m_clients;

			thread handleClient(&Communicator::startThreadForNewClient, acceptSocket);
			handleClient.detach();
		}
	}
}
