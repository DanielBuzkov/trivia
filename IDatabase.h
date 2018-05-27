#pragma once

#include <list>
#include <map>
#include "LoggedUser.h"

using namespace std;

class IDatabase
{
public:
	map<LoggedUser, int> getHighscores();
	bool doesUserExiste(string);
	list<Question> getQuestions(int);
};