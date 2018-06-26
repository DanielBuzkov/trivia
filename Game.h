#pragma once

//unclear

#include "Question.h"
#include "Protocol.h"
#include "LoggedUser.h"

#include <vector>
#include <map>

class Game
{
private:
	vector<Question> m_questions;
	map<LoggedUser, GameData> m_players;

public:
	void getQuestionsForUser(LoggedUser); //param type was User
	void submitAnswer();
	void removePlayer();
};