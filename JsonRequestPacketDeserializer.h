#pragma once

#include <vector>
#include "Protocol.h"

using namespace std;

class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(vector<uint8_t>);
	static SignupRequest deserializeSignupRequest(vector<uint8_t>);
};
