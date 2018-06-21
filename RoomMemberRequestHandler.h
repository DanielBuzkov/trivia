#pragma once

#include "Protocol.h"
#include "RequestHandlerFactory.h"
#include "JsonRequestPacketDeserializer.h"
#include "LoginManager.h"
#include "IRequsetHandler.h"

//TODO
//	update next stage handler

class RoomMemberRequestHandler : public IRequsetHandler
{
public:
	RoomMemberRequestHandler();

	bool isRequestRelevant(Request r);
	RequestResult handleRequest(Request r);

private:
	Room m_room;
	LoggedUser m_user;
	RoomManager m_roomManager;
	RequestHandlerFactory m_handlerFactory;

	RequestResult leaveRoom(Request r);
	RequestResult getRoomState(Request r);
};