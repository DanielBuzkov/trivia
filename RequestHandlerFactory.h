#pragma once

#include "LoginManager.h"
#include "IRequsetHandler.h"
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "RoomManager.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "GameRequestHandler.h"
#include "HighscoreTable.h"

static class RequestHandlerFactory
{
public:
	RequestHandlerFactory() {}

	static LoginRequestHandler createLoginRequestHandler()
	{
		return LoginRequestHandler();
	}

	static MenuRequestHandler createMenuRequestHandler()
	{
		return MenuRequestHandler();
	}

	static RoomAdminRequestHandler createRoomAdminRequestHandler()
	{
		return RoomAdminRequestHandler();
	}

	static RoomMemberRequestHandler createRoomMemeberRequestHandler()
	{
		return RoomMemberRequestHandler();
	}

	static GameRequestHandler createGameRequestHandler()
	{
		return GameRequestHandler();
	}

private:
	static LoginManager m_loginManager;
	static RoomManager m_roomManager;
	static HighscoreTable m_highscoreTable;
};