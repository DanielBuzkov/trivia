#include "RoomMemberRequestHandler.h"

RoomMemberRequestHandler::RoomMemberRequestHandler()
{
	m_room = Room();
	m_user = LoggedUser();
	m_roomManager = RoomManager();
	m_handlerFactory = RequestHandlerFactory();
}

bool RoomMemberRequestHandler::isRequestRelevant(Request r)
{
	return r.id == LEAVE_ROOM_REQUEST || r.id == GET_ROOM_STATE_REQUEST;
}

RequestResult RoomMemberRequestHandler::handleRequest(Request r)
{
	if (isRequestRelevant(r))
		return r.id == LEAVE_ROOM_REQUEST ? leaveRoom(r) : getRoomState(r);

	RequestResult fail;
	fail.Response = JsonResponsePacketSerializer::serializeResponse(ErrorResponse());
	fail.newHandler = nullptr;
}

RequestResult RoomMemberRequestHandler::leaveRoom(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse());
	success.newHandler = &RequestHandlerFactory::createMenuRequestHandler(); //back to menu from room

	return success;
}

RequestResult RoomMemberRequestHandler::getRoomState(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse());

	//Check if game started and then newHandler = game

	return success;
}
