#pragma once
//TODO:
//	How do I know which user to remove or add?


#include "Protocol.h"
#include "LoggedUser.h"

class Room
{
private:
	RoomData m_metadata;
	vector<LoggedUser> m_users;

public:
	Room();

	RoomData getData() { return m_metadata; }
	vector<LoggedUser> getAllUsers() { return m_users; } //return type was void

	void addUser();
	void removeUser();
	
};