#include "LoginRequestHandler.h"

LoginRequestHandler::LoginRequestHandler()
{
	m_loginManager = LoginManager();
}

bool LoginRequestHandler::isRequestRelevant(Request r)
{
	return r.id == LOGIN_REQUEST || r.id == SIGNUP_REQUEST;
}

RequestResult LoginRequestHandler::handleRequest(Request r)
{
	try {
		if (isRequestRelevant(r))
			return r.id == LOGIN_REQUEST ? login(r) : signup(r);
	}
	catch (exception &e){}

	RequestResult fail;
	fail.Response = JsonResponsePacketSerializer::serializeResponse(ErrorResponse());
	fail.newHandler = nullptr;
	return fail;
}

RequestResult LoginRequestHandler::login(Request r)
{
	LoginRequest currRequest = JsonRequestPacketDeserializer::deserializeLoginRequest(r.buffer);
	m_loginManager.login(currRequest.name, currRequest.password);

	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(LoginResponse());
	success.newHandler = &RequestHandlerFactory::createMenuRequestHandler();

	return success;
}

RequestResult LoginRequestHandler::signup(Request r)
{
	SignupRequest currRequest = JsonRequestPacketDeserializer::deserializeSignupRequest(r.buffer);
	m_loginManager.signup(currRequest.email, currRequest.name, currRequest.password);

	RequestResult success;
	success.Response = JsonResponsePacketSerializer::serializeResponse(SignupResponse());
	success.newHandler = &RequestHandlerFactory::createMenuRequestHandler();

	return success;
}