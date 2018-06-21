#pragma once
#include <vector>

using namespace std;

class Question
{
private:
	string m_question;
	vector<string> m_possibleAnswers;

public:
	string getQuestion();
	string getPossibleAnswers();
	string getCorrentAnswer();
};