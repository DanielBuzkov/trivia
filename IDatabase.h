#pragma once
//TODO
//	getQuestions
//	+more


#include <list>
#include <map>
#include "LoggedUser.h"
#include "sqlite3.h"
#include "Question.h"

using namespace std;

#define DB_NAME ""

class IDatabase
{
private:
	sqlite3* _sqlite;

	static int highScoreCallback(void* res, int argc, char** argv, char** azCol)
	{
		map<LoggedUser, int>* currRowRes = (map<LoggedUser, int>*)res;

		currRowRes->insert(pair<LoggedUser, int>(LoggedUser(argv[0]), stoi(argv[1])));

		return 0;
	}

	static int countCallback(void* res, int argc, char** argv, char** azCol)
	{
		int*  ret = (int*)res;
		*ret = atoi(argv[0]);

		return 0;
	}

	static int callbackPersonalStatus(void* res, int argc, char** argv, char** azCol)
	{
		vector<string> ret;
		ret.insert(argv[0]);
	}

public:
	IDatabase()
	{
		if (sqlite3_open(DB_NAME, &_sqlite)) 
		{
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(_sqlite));
			return;
		}
	}

	~IDatabase()
	{
		sqlite3_close(_sqlite);
		_sqlite = nullptr;
	}

	map<LoggedUser, int> getHighscores()
	{
		//Top 3 scores
		std::string query = "SELECT username, sum(is_correct) as ans from players_answers group by username order by ans DESC limit 3";

		map<LoggedUser, int> res;

		char *zErrMsg = 0;

		if (sqlite3_exec(_sqlite, query.c_str(), highScoreCallback, &res, &zErrMsg) != SQLITE_OK)
			sqlite3_free(zErrMsg);

		return res;
	}
	
	bool doesUserExiste(string username)
	{
		std::string query = "SELECT count(*) FROM Users where username = \'" + username + "\'";

		int res = 0;
		char *zErrMsg = 0;
		if (sqlite3_exec(_sqlite, query.c_str(), countCallback, &res, &zErrMsg) != SQLITE_OK)
		{
			//ERROR
			sqlite3_free(zErrMsg);
			return false;
		}
		return res != 0;
	}
	
	list<Question> getQuestions(int);

	bool addNewUser(string username, string password, string email)
	{
		std::string sql = "insert into Users (username, password, email) values(\'" + username + "\', \'" + password + "\', \'" + email + "\')";
		char *zErrMsg = 0;
		int m = sqlite3_exec(_sqlite, sql.c_str(), nullptr, nullptr, &zErrMsg);

		if (m != SQLITE_OK)
		{
			sqlite3_free(zErrMsg);
			return false;
		}

		return true;
	}

	bool isUserAndPassMatch(string username, string password)
	{
		std::string sql = "select count(*) from Users where username = \'" + username + "\' and password = \'" + password + "\'";
		int res = 0;

		char *zErrMsg = 0;
		int m = sqlite3_exec(_sqlite, sql.c_str(), countCallback, &res, &zErrMsg);

		if (m != SQLITE_OK)
		{
			sqlite3_free(zErrMsg);
			return false;
		}

		return res == 1;
	}

	vector<Question*> initQuestions(int questionsNo)
	{
		std::string sql = "select question_id, question, correct_ans, ans2, ans3, ans4 from t_questions order by random() limit " + to_string(questionsNo);

		vector<Question*> res;

		char *zErrMsg = 0;
		int m = sqlite3_exec(_sqlite, sql.c_str(), callbackQuestions, &res, &zErrMsg);

		if (m != SQLITE_OK)
		{
			sqlite3_free(zErrMsg);
		}


		return res;
	}

	vector<string> getPersonalStatus(string username)
	{
		std::string sql = "select  count(distinct game_id), sum(is_correct) as  correct, count(*) - sum(is_correct), avg(answer_time) from players_answers where username = '" + username + "'";

		vector<std::string> res;

		char *zErrMsg = 0;
		int m = sqlite3_exec(_sqlite, sql.c_str(), callbackPersonalStatus, &res, &zErrMsg);

		if (m != SQLITE_OK)
		{
			sqlite3_free(zErrMsg);
		}


		return res;
	}

	int insertNewGame()
	{
		std::string sql = "insert into t_games (status, start_time) values(0, DATETIME(\'now\'))";
		char *zErrMsg = 0;
		int m = sqlite3_exec(_sqlite, sql.c_str(), nullptr, nullptr, &zErrMsg);

		if (m != SQLITE_OK)
		{
			sqlite3_free(zErrMsg);
			return -1;
		}

		sql = "select last_insert_rowid()";
		int res = 0;

		m = sqlite3_exec(_sqlite, sql.c_str(), callbackCount, &res, &zErrMsg);

		if (m != SQLITE_OK)
		{
			sqlite3_free(zErrMsg);
			return -1;
		}

		return res;
	}

	bool updateGameStatus(int id)
	{
		std::string sql = "update t_games set status=1, end_time=DATETIME(\'now\') where game_id = " + to_string(id);
		char *zErrMsg = 0;
		int m = sqlite3_exec(_sqlite, sql.c_str(), nullptr, nullptr, &zErrMsg);

		if (m != SQLITE_OK)
		{
			sqlite3_free(zErrMsg);
			return false;
		}

		return true;
	}

	bool addAnwerToPlayer(int gameId, string username, int questionId, string answer, bool isCorrect, int answerTime)
	{
		std::string sql = "insert into t_players_answers (game_id, username, question_id, player_answer, is_correct, answer_time) values(" + to_string(gameId) + ", \'" + username + "\', " + to_string(questionId) +
			", \'" + answer + "\', " + to_string(isCorrect ? 1 : 0) + ", " + to_string(answerTime) + ")";

		char *zErrMsg = 0;
		int m = sqlite3_exec(_sqlite, sql.c_str(), nullptr, nullptr, &zErrMsg);

		if (m != SQLITE_OK)
		{
			sqlite3_free(zErrMsg);
			return false;
		}

		return true;

	}
};