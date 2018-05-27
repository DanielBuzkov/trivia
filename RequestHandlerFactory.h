#pragma once

#include "LoginManager.h"
#include "LoginRequestHandler.h"

class RequestHandlerFactory
{
public:
	LoginRequestHandler createLoginRequestHandler()
	{
		return LoginRequestHandler();
	}

private:
	LoginManager m_loginManager;
};