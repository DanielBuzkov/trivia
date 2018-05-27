#pragma once

#include <vector>
#include "Protocol.h"

using namespace std;

class JsonResponsePacketSerializer
{
public:
	static vector<uint8_t> serializeResponse(ErrorResponse);
	static vector<uint8_t> serializeResponse(LoginResponse);
	static vector<uint8_t> serializeResponse(SignupResponse);
};
