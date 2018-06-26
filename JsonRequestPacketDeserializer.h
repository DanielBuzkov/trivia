#pragma once
//how do i convert strings? (unknown len) login and signup

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

	static GetPlayersInRoomRequest deserializeGetPlayersRequest(vector<uint8_t> buffer)
	{
		GetPlayersInRoomRequest ret;
		ret.roomId = (uint32_t)buffer[0] << 24 |
			(uint32_t)buffer[1] << 16 |
			(uint32_t)buffer[2] << 8 |
			(uint32_t)buffer[3] << 0;
		return ret;
	}
	static JoinRoomRequest deserializeJoinRoomRequest(vector<uint8_t> buffer)
	{
		JoinRoomRequest ret;
		ret.roomId = (uint32_t)buffer[0] << 24 |
			(uint32_t)buffer[1] << 16 |
			(uint32_t)buffer[2] << 8 |
			(uint32_t)buffer[3] << 0;		
		return ret;
	}
	static CreateRoomRequest deserializeCreateRoomRequest(vector<uint8_t> buffer)
	{
		CreateRoomRequest ret;
		ret.maxUsers = (uint32_t)buffer[0] << 24 |
			(uint32_t)buffer[1] << 16 |
			(uint32_t)buffer[2] << 8 |
			(uint32_t)buffer[3] << 0;
		ret.questionCount = (uint32_t)buffer[4] << 24 |
			(uint32_t)buffer[5] << 16 |
			(uint32_t)buffer[6] << 8 |
			(uint32_t)buffer[7] << 0;
		ret.answerTimeout = (uint32_t)buffer[8] << 24 |
			(uint32_t)buffer[9] << 16 |
			(uint32_t)buffer[10] << 8 |
			(uint32_t)buffer[11] << 0;
		memcpy(&ret.roomName, &buffer + 12, buffer.size() - 12);
		return ret;
	}

	static SubmitAnswerRequest deserializeSubmitAnswerRequest(vector<uint8_t> buffer) 
	{
		//type was submitBufferRequest
		SubmitAnswerRequest ret;
		ret.answerId = (uint32_t)buffer[0] << 24 |
			(uint32_t)buffer[1] << 16 |
			(uint32_t)buffer[2] << 8 |
			(uint32_t)buffer[3] << 0;
		return ret;
	}
};
