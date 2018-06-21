#pragma once

//TODO:
// logout - how do i know who to logout?

#include "IDatabase.h"
#include "LoggedUser.h"
#include <vector>

using namespace std;

class LoginManager
{
private:
	IDatabase m_database;
	vector<LoggedUser> m_loggedUsers;

public:
	void signup(string email, string name, string password)
	{
		if (!m_database.addNewUser(name, password, email))
			throw "ERROR : unable to add user to db";
	}

	void login(string name, string password)
	{
		m_loggedUsers.push_back(LoggedUser(name));
	}

	void logout();
};