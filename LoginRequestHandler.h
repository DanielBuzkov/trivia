#pragma once

//TODO
//	login and signup newHandler?

#include "Protocol.h"
#include "RequestHandlerFactory.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "LoginManager.h"
#include "IRequsetHandler.h"

class LoginRequestHandler : public IRequsetHandler
{
public:
	LoginRequestHandler();

	bool isRequestRelevant(Request r);
	RequestResult handleRequest(Request r);

private:
	LoginManager m_loginManager;
	//RequestHandlerFactory m_handlerFactory;

	RequestResult login(Request r);
	RequestResult signup(Request r);
};