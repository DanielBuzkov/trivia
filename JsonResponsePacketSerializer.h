#pragma once

#include <vector>
#include "Protocol.h"

using namespace std;

static class JsonResponsePacketSerializer
{
public:
	static vector<uint8_t> serializeResponse(ErrorResponse res) {
		vector<uint8_t> ret;
		for (int i = 0; i < sizeof(res); i++)
			ret[i] = res.message[i];
		return ret;
	}
	static vector<uint8_t> serializeResponse(LoginResponse res) {
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;
		return ret;
	}
	static vector<uint8_t> serializeResponse(SignupResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;
		return ret;
	}

	static vector<uint8_t> serializeResponse(LogoutResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;
		return ret;
	}
	static vector<uint8_t> serializeResponse(GetRoomsResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;

		for (int i = 0; i < sizeof(res.rooms); i++)
			ret[4 + i] = (uint8_t)((&res.rooms) + i);

		return ret;
	}
	static vector<uint8_t> serializeResponse(GetPlayersInRoomResponse res)
	{
		vector<uint8_t> ret;

		for (int i = 0; i < sizeof(res.players); i++)
			ret[i] = (uint8_t)((&res.players) + i);

		return ret;
	}
	static vector<uint8_t> serializeResponse(JoinRoomResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;
		return ret;
	}
	static vector<uint8_t> serializeResponse(CreateRoomResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;
		return ret;
	}
	static vector<uint8_t> serializeResponse(HighscoreResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;

		for (int i = 0; i < sizeof(res.highscores); i++)
			ret[4 + i] = (uint8_t)((&res.highscores) + i);

		return ret;
	}

	static vector<uint8_t> serializeResponse(CloseRoomResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;
		return ret;
	}
	static vector<uint8_t> serializeResponse(StartGameResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;
		return ret;
	}
	static vector<uint8_t> serializeResponse(GetRoomStateResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;

		ret[4] = res.hasGameBegun;

		int i = 0;
		for (i = 0; i < sizeof(res.players); i++)
			ret[5 + i] = (uint8_t)((&res.players) + i);

		ret[5 + i++] = res.questionCount;
		ret[5 + i++] = (static_cast<unsigned int>(res.questionCount) >> 8) & 0xFF;
		ret[5 + i++] = (static_cast<unsigned int>(res.questionCount) >> 16) & 0xFF;
		ret[5 + i] = (static_cast<unsigned int>(res.questionCount) >> 24) & 0xFF;

		return ret;
	}
	static vector<uint8_t> serializeResponse(LeaveRoomResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;
		return ret;
	}

	static vector<uint8_t> serializeResponse(GetGameResultResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;

		for (int i = 0; i < sizeof(res.results); i++)
			ret[5 + i] = (uint8_t)((&res.results) + i);

		return ret;
	}
	static vector<uint8_t> serializeResponse(SubmitAnswerResponse res)
	{
		vector<uint8_t> ret;
		ret[0] = res.status;
		ret[1] = (static_cast<unsigned int>(res.status) >> 8) & 0xFF;
		ret[2] = (static_cast<unsigned int>(res.status) >> 16) & 0xFF;
		ret[3] = (static_cast<unsigned int>(res.status) >> 24) & 0xFF;

		ret[4] = res.correctAnswerId;
		ret[5] = (static_cast<unsigned int>(res.correctAnswerId) >> 8) & 0xFF;
		ret[6] = (static_cast<unsigned int>(res.correctAnswerId) >> 16) & 0xFF;
		ret[7] = (static_cast<unsigned int>(res.correctAnswerId) >> 24) & 0xFF;

		return ret;
	}
};
