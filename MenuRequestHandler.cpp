#include "MenuRequestHandler.h"

//Update handler for next stage

MenuRequestHandler::MenuRequestHandler()
{
	m_user = LoggedUser();
	m_roomManager = RoomManager();
	m_highscoreTable = HighscoreTable();
}

bool MenuRequestHandler::isRequestRelevant(Request r)
{
	return r.id == SIGNOUT_REQUEST ||
		r.id == GET_ROOMS_REQUEST ||
		r.id == GET_PLAYERS_IN_ROOM_REQUEST ||
		r.id == GET_HIGHSCORES_REQUEST ||
		r.id == JOIN_ROOM_REQUEST ||
		r.id == CREATE_ROOM_REQUEST;
}

RequestResult MenuRequestHandler::signout(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(LogoutResponse());
	success.newHandler = nullptr;

	return success;
}

RequestResult MenuRequestHandler::getRooms(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(LogoutResponse());

	return success;
}

RequestResult MenuRequestHandler::getPlayersInRoom(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse());

	return success;
}

RequestResult MenuRequestHandler::getHighscores(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(HighscoreResponse());

	return success;
}

RequestResult MenuRequestHandler::joinRoom(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(JoinRoomResponse());
	success.newHandler = &RequestHandlerFactory::createRoomMemeberRequestHandler();

	return success;
}

RequestResult MenuRequestHandler::createRoom(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(CreateRoomResponse());
	success.newHandler = &RequestHandlerFactory::createRoomAdminRequestHandler();

	return success;
}

RequestResult MenuRequestHandler::handleRequest(Request r)
{
	if (isRequestRelevant)
	{
		if (r.id == SIGNOUT_REQUEST)
			return signout(r);
		else if (r.id == GET_ROOMS_REQUEST)
			return getRooms(r);
		else if (r.id == GET_PLAYERS_IN_ROOM_REQUEST)
			return getPlayersInRoom(r);
		else if (r.id == GET_HIGHSCORES_REQUEST)
			return getHighscores(r);
		else if (r.id == JOIN_ROOM_REQUEST)
			return joinRoom(r);
		else if (r.id == CREATE_ROOM_REQUEST)
			return createRoom(r);
	}
	else
	{
		RequestResult fail;
		fail.Response = JsonResponsePacketSerializer::serializeResponse(ErrorResponse());
		fail.newHandler = nullptr;
	}
}
