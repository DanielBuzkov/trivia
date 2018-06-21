#pragma once

#include "Protocol.h"

class IRequsetHandler
{
public:
	virtual bool isRequestRelevant(Request) = 0;
	virtual RequestResult handleRequest(Request) = 0; //Abstract function will be overriden 
};