#pragma once
//how do i do it

#include <vector>
#include "Protocol.h"

using namespace std;

class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(vector<uint8_t> buffer)
	{
		LoginRequest ret;
		//ret.name =
	}
	static SignupRequest deserializeSignupRequest(vector<uint8_t> buffer);

	static GetPlayersInRoomRequest deserializeGetPlayersRequest(vector<uint8_t> buffer);
	static JoinRoomRequest deserializeJoinRoomRequest(vector<uint8_t> buffer);
	static CreateRoomRequest deserializeCreateRoomRequest(vector<uint8_t> buffer);

	static SubmitAnswerRequest deserializeSubmitAnswerRequest(vector<uint8_t> buffer); //type was submitBufferRequest
};
