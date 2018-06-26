#pragma once

#include "Protocol.h"
#include "RequestHandlerFactory.h"
#include "JsonRequestPacketDeserializer.h"
#include "LoginManager.h"
#include "IRequsetHandler.h"


class MenuRequestHandler : public IRequsetHandler
{
public:
	MenuRequestHandler();

	bool isRequestRelevant(Request r);
	RequestResult handleRequest(Request r);

private:
	LoggedUser m_user;
	RoomManager m_roomManager;
	HighscoreTable m_highscoreTable;
	//RequestHandlerFactory m_handlerFactory;

	RequestResult signout(Request r);
	RequestResult getRooms(Request r);
	RequestResult getPlayersInRoom(Request r);
	RequestResult getHighscores(Request r);
	RequestResult joinRoom(Request r);
	RequestResult createRoom(Request r);

};