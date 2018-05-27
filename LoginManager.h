#pragma once

#include "LoggedUser.h"
#include <vector>

using namespace std;

class LoginManager
{
private:
	IDatabase m_database;
	vector<LoggedUser> m_loggedUsers;

public:
	void signup(string, string, string);
	void login(string, string);
	void logout();
};