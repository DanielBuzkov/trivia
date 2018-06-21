#include "RoomAdminRequestHandler.h"

//update next state after start game

RoomAdminRequestHandler::RoomAdminRequestHandler()
{
	m_room = Room();
	m_user = LoggedUser();
	m_roomManager = RoomManager();
	m_handlerFactory = RequestHandlerFactory();
}

bool RoomAdminRequestHandler::isRequestRelevant(Request r)
{
	return r.id == CLOSE_ROOM_REQUEST || r.id == GET_ROOM_STATE_REQUEST || r.id == START_GAME_REQUEST;
}

RequestResult RoomAdminRequestHandler::handleRequest(Request r)
{
	if (isRequestRelevant(r))
	{
		if (r.id == LEAVE_ROOM_REQUEST)
			return closeRoom(r);
		else if (r.id == GET_ROOM_STATE_REQUEST)
			return getRoomState(r);
		else
			return startGame(r);
	}

	RequestResult fail;
	fail.Response = JsonResponsePacketSerializer::serializeResponse(ErrorResponse());
	fail.newHandler = nullptr;
}

RequestResult RoomAdminRequestHandler::closeRoom(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(CloseRoomResponse());
	success.newHandler = &RequestHandlerFactory::createMenuRequestHandler(); //back to menu from room

	return success;
}

RequestResult RoomAdminRequestHandler::getRoomState(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse());

	return success;
}

RequestResult RoomAdminRequestHandler::startGame(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse());
	success.newHandler = &RequestHandlerFactory::createGameRequestHandler();

	return success;
}
