#include "GameRequestHandler.h"

GameRequestHandler::GameRequestHandler()
{
	m_game = Game();
	m_gameManager = GameManager();
	m_user = LoggedUser();
}

bool GameRequestHandler::isRequestRelevant(Request r)
{
	return r.id == GET_QUESTION_REQUEST || r.id == SUBMIT_ANSWER_REQUEST ||
		r.id == GET_GAME_RESULTS_REQUEST || r.id == LEAVE_GAME_REQUEST;
}

RequestResult GameRequestHandler::handleRequest(Request r)
{
	if (isRequestRelevant(r))
	{
		if (r.id == GET_QUESTION_REQUEST)
			return getQuestions(r);
		else if (r.id == SUBMIT_ANSWER_REQUEST)
			return submitAnswers(r);
		else if (r.id == GET_GAME_RESULTS_REQUEST)
			return getGameResults(r);
		else if (r.id == LEAVE_GAME_REQUEST)
			return leaveGame(r);
	}

	RequestResult fail;
	fail.Response = JsonResponsePacketSerializer::serializeResponse(ErrorResponse());
	fail.newHandler = nullptr;
	return fail;
}

RequestResult GameRequestHandler::getQuestions(Request r)
{
	RequestResult success;

	return success;
}

RequestResult GameRequestHandler::submitAnswers(Request r)
{
	SubmitAnswerRequest currRequest = JsonRequestPacketDeserializer::deserializeSubmitAnswerRequest(r.buffer);
	m_game.submitAnswer(); //WHY IS DIS NO PARAM

	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(SubmitAnswerResponse());

	return success;
}

RequestResult GameRequestHandler::getGameResults(Request r)
{
	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(GetGameResultResponse());

	return success;
}

RequestResult GameRequestHandler::leaveGame(Request r)
{
	RequestResult success;
	//success.Response = JsonResponsePacketSerializer::serializeResponse(LeaveGameResponse()); where is it?
	success.newHandler = &RequestHandlerFactory::createMenuRequestHandler();

	return success;
}