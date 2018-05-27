#pragma once

#include <string>

using namespace std;

//Function "getUsername" had "void" as return type instead of "string"

class LoggedUser
{
private:
	string m_username;

public:
	string getUsername() { return m_username; }
};