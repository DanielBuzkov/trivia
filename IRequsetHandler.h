#pragma once

#include "Protocol.h"

class IRequsetHandler
{
public:
	bool isRequestRelevant(Request);
	virtual RequestResult handleRequest(Request) = 0; //Abstract function will be overriden 
};