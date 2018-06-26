#pragma once

//#include "Buffer.h"
#include "IRequsetHandler.h"
#include "Question.h"
#include <vector>
#include <time.h>

using namespace std;

//TODO:
//	@ getRoomState - answerTimeOut type?

//conts
#define MAX_MESSAGE_LEN 4294967295

//Message codes:
//Request - ends with an 0
//Response - ends with a 1
#define FAILED 000
#define LOGIN_REQUEST 100
#define LOGIN_RESPONSE 101
#define SIGNUP_REQUEST 110
#define SIGNUP_RESPONSE 111

#define SIGNOUT_REQUEST 120
#define SIGNOUT_RESPONSE 121
#define GET_ROOMS_REQUEST 130
#define GET_ROOMS_RESPONSE 131
#define GET_PLAYERS_IN_ROOM_REQUEST 140
#define GET_PLAYERS_IN_ROOM_RESPONSE 141
#define GET_HIGHSCORES_REQUEST 150
#define GET_HIGHSCORES_RESPONSE 151
#define JOIN_ROOM_REQUEST 160
#define JOIN_ROOM_RESPONSE 161
#define CREATE_ROOM_REQUEST 170
#define CREATE_ROOM_RESPONSE 171

#define CLOSE_ROOM_REQUEST 180
#define CLOSE_ROOM_RESPONSE 181
#define START_GAME_REQUEST 190
#define START_GAME_RESPONSE 191
#define GET_ROOM_STATE_REQUEST 200
#define GET_ROOM_STATE_RESPONSE 201
#define LEAVE_ROOM_REQUEST 210
#define LEAVE_ROOM_RESPONSE 211

#define GET_QUESTION_REQUEST 220
#define GET_QUESTION_RESPONSE 221
#define SUBMIT_ANSWER_REQUEST 230
#define SUBMIT_ANSWER_RESPONSE 231
#define GET_GAME_RESULTS_REQUEST 240
#define GET_GAME_RESULTS_RESPONSE 241
#define LEAVE_GAME_REQUEST 250
#define LEAVE_GAME_RESPONSE 251

struct RequestResult
{
	vector<uint8_t> Response; //why is this a vector
	IRequsetHandler* newHandler;
};

struct Request
{
	int id; 
	time_t receivalTime; 
	vector<uint8_t> buffer;
};

struct RoomData
{
	unsigned int id;
	string name;
	string maxPlayer; //why string bro?
	unsigned int timePerQuestion;
	unsigned int isActive;
};

struct PlayerResults
{
	string username;
	unsigned int correctAnswerCount;
	unsigned int wrongAnwerCount;
	unsigned int avarageAnswerTime;
};

struct GameData
{
	Question currentQuestion;
	unsigned int correctAnwerCount;
	unsigned int wrongAnswerCount;
	unsigned int averageAnswerTime;
};

//RESPONSES
struct ErrorResponse
{
	string message;
};

struct LoginResponse
{
	unsigned int status = LOGIN_RESPONSE;
};

struct SignupResponse
{
	unsigned int status = SIGNUP_RESPONSE;
};

struct LogoutResponse
{
	unsigned int status = SIGNOUT_RESPONSE;
};

struct GetRoomsResponse
{
	unsigned int status = GET_ROOMS_RESPONSE;
	vector<RoomData> rooms;
};

struct GetPlayersInRoomResponse
{
	vector<string> players;
};

struct HighscoreResponse
{
	unsigned int status = GET_HIGHSCORES_RESPONSE;
	vector<int> highscores; //vector of "highcore" ??
};

struct JoinRoomResponse
{
	unsigned int status = JOIN_ROOM_RESPONSE;
};

struct CreateRoomResponse
{
	unsigned int status = CREATE_ROOM_RESPONSE;
};

struct CloseRoomResponse
{
	unsigned int status = CLOSE_ROOM_RESPONSE;
};

struct StartGameResponse
{
	unsigned int status = START_GAME_RESPONSE;
};

struct GetRoomStateResponse
{
	unsigned int status = GET_ROOM_STATE_RESPONSE;
	bool hasGameBegun = false;
	vector<string> players;
	unsigned int questionCount;
	//answerTimeOut?
};

struct LeaveRoomResponse
{
	unsigned int status = LEAVE_ROOM_RESPONSE;
};

struct GetQuestionResponse
{
	unsigned int status = GET_QUESTION_RESPONSE;
	string question;
	map<unsigned int, string> answers;
};

struct SubmitAnswerResponse
{
	unsigned int status = SUBMIT_ANSWER_RESPONSE;
	unsigned int correctAnswerId;
};

struct GetGameResultResponse
{
	unsigned int status = GET_GAME_RESULTS_RESPONSE;
	vector<PlayerResults> results;
};

//REQUESTS
struct LoginRequest
{
	string name;
	string password;
};

struct SignupRequest
{
	string name;
	string password;
	string email;
};

struct GetPlayersInRoomRequest
{
	unsigned int roomId;
};

struct JoinRoomRequest
{
	unsigned int roomId;
};

struct CreateRoomRequest
{
	unsigned int maxUsers;
	unsigned int questionCount;
	unsigned int answerTimeout;
	string roomName;
};

struct SubmitAnswerRequest
{
	unsigned int answerId;
};
