#pragma once
#include <vector>

using namespace std;

class Question
{
private:
	string m_question;
	vector<string> m_possibleAnswers; //first option is the correct one

public:
	string getQuestion() { return m_question; }
	vector<string> getPossibleAnswers() { return m_possibleAnswers; }
	string getCorrentAnswer() { return m_possibleAnswers[0]; }
};