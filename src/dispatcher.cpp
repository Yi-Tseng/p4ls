#include "dispatcher.h"

#include <iostream>

void Dispatcher::register_handler(const std::string &method, handler_type handler)
{
	handlers[method] = std::move(handler);
	std::cout << __PRETTY_FUNCTION__ << " registered method " << method << std::endl;
}

bool Dispatcher::call(rapidjson::Document &msg) const
{
	if (!msg.HasMember("jsonrpc") || !msg["jsonrpc"].IsString() || msg["jsonrpc"] != "2.0")
	{
		return false;
	}
	if (!msg.HasMember("method") || !msg["method"].IsString())
	{
		return false;
	}
	auto handler = handlers.find(msg["method"].GetString());
	if (handler != handlers.end())
	{
		handler->second(std::move(msg["params"].GetObject()));
	}
	return true;
}
