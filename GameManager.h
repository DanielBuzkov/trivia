#pragma once

//TODO:
//	why do i get Room for ceateGame?
//	how do i deleteGame

#include "IDatabase.h"
#include "Game.h"
#include "Room.h"
#include <vector>

using namespace std;

class GameManager
{
private:
	IDatabase m_database;
	vector<Game> m_games;

public:
	Game createGame(Room currRoom)
	{
		m_database.insertNewGame();

		Game newGame = Game();
		m_games.push_back(newGame);

		return newGame;
	}

	void deleteGame()
	{
		//What do i do here
	}
};