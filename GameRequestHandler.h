#pragma once

#pragma once

#include "Protocol.h"
#include "RequestHandlerFactory.h"
#include "JsonRequestPacketDeserializer.h"
#include "IRequsetHandler.h"
#include "Game.h"
#include "GameManager.h"

class GameRequestHandler : public IRequsetHandler
{
public:
	GameRequestHandler();

	bool isRequestRelevant(Request r);
	RequestResult handleRequest(Request r);

private:
	Game m_game;
	LoggedUser m_user;
	GameManager m_gameManager;
	//RequestHandlerFactory m_handlerFactory;

	RequestResult getQuestions(Request r);
	RequestResult submitAnswers(Request r);
	RequestResult getGameResults(Request r);
	RequestResult leaveGame(Request r);
};