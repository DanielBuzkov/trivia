#pragma once

#include "Protocol.h"
#include "RequestHandlerFactory.h"
#include "JsonRequestPacketDeserializer.h"
#include "LoginManager.h"
#include "IRequsetHandler.h"


class RoomAdminRequestHandler : public IRequsetHandler
{
public:
	RoomAdminRequestHandler();

	bool isRequestRelevant(Request r);
	RequestResult handleRequest(Request r);

private:
	Room m_room;
	LoggedUser m_user;
	RoomManager m_roomManager;
	//RequestHandlerFactory m_handlerFactory;

	RequestResult closeRoom(Request r);
	RequestResult startGame(Request r);
	RequestResult getRoomState(Request r);
};