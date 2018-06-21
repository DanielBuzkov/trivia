#pragma once
//TODO
//	why there are 4 serilizers at the table?

#include <vector>
#include "Protocol.h"

using namespace std;

static class JsonResponsePacketSerializer
{
public:
	static vector<uint8_t> serializeResponse(ErrorResponse res) {
		/*vector<uint8_t> ret;
		char buffer[sizeof(res)];

		memcpy(buffer, &res, sizeof(res));

		for each (char currByte in buffer)
			ret.push_back(currByte);

		return ret;*/
	}
	static vector<uint8_t> serializeResponse(LoginResponse res) {
		vector<uint8_t> ret;
		res.
	}
	static vector<uint8_t> serializeResponse(SignupResponse res);

	static vector<uint8_t> serializeResponse(LogoutResponse res);
	static vector<uint8_t> serializeResponse(GetRoomsResponse res);
	static vector<uint8_t> serializeResponse(GetPlayersInRoomResponse res);
	static vector<uint8_t> serializeResponse(JoinRoomResponse res);
	static vector<uint8_t> serializeResponse(CreateRoomResponse res);
	static vector<uint8_t> serializeResponse(HighscoreResponse res);

	static vector<uint8_t> serializeResponse(CloseRoomResponse res);
	static vector<uint8_t> serializeResponse(StartGameResponse res);
	static vector<uint8_t> serializeResponse(GetRoomStateResponse res);
	static vector<uint8_t> serializeResponse(LeaveRoomResponse res);

	static vector<uint8_t> serializeResponse(GetGameResultResponse res);
	static vector<uint8_t> serializeResponse(SubmitAnswerResponse res);
};
