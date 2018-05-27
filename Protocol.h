#pragma once

//#include "Buffer.h"
#include "IRequsetHandler.h"
#include <vector>
#include <time.h>

using namespace std;

struct RequestResult
{
	vector<uint8_t> Responser;
	IRequsetHandler* newHandler;
};

struct Request
{
	RequestId id; //int?
	ctime receivalTime; //what
	vector<uint8_t> buffer;
};


//RESPONSES
struct ErrorResponse
{
	string message;
};

struct LoginResponse
{
	unsigned int status;
};

struct SignupResponse
{
	unsigned int status;
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

//Message codes:
//Request - ends with an 0
//Response - ends with a 1
#define LOGIN_REQUEST 100
#define LOGIN_RESPONSE 101
#define SIGNUP_REQUEST 110
#define SUGNUP_RESPONSE 111
