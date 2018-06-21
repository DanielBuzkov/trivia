#pragma once
//TODO
//	what is the room state?
//	how do i know which room to delete


#include "Room.h"
#include <map>

class RoomManager
{
private:
	map<int, Room> m_rooms; //int as room ID
	int currID;

public:
	RoomManager()
	{
		currID = 0;
	}

	void createRoom(LoggedUser admin)
	{
		m_rooms.insert(pair<int, Room>(currID++, Room()));
	}

	void deleteRoom();

	unsigned int getRoomState(int ID)
	{
		//what?
	}
	
	vector<RoomData> getRooms()
	{
		vector<RoomData> ret;

		for each(pair<int, Room> currRoom in m_rooms)
			ret.push_back(currRoom.second.getData());

		return ret;
	}
};