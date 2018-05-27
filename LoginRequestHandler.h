#pragma once

#include "Protocol.h"
#include "RequestHandlerFactory.h"
#include "IRequsetHandler.h"

class LoginRequestHandler : public IRequsetHandler
{
public:
	LoginRequestHandler();

	bool isRequestRelevant(Request);
	RequestResult handleRequest(Request);

private:
	LoginManager m_loginManager;
	RequestHandlerFactory m_handlerFactory;

	RequestResult login(Request); 
	RequestResult signup(Request);
};