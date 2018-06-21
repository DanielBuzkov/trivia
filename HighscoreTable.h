#pragma once
#include "IDatabase.h"

class HighscoreTable
{
private:
	IDatabase m_database;

public:
	map<LoggedUser, int> getHighscores() { return m_database.getHighscores(); } //ret type was void
};