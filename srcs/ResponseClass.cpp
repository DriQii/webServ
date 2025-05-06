#include "ResponseClass.hpp"

void Response::_initFile()
{
	_ssFile << _istream.rdbuf();
	_file = _ssFile.str();
	_ssSize << _file.size();
	//if (_path.size() >= 5 && _path.compare(_path.size() - 5, 5, ".html") == 0)
	_type = "text/html";

}

Response::Response(std::string path) : _path(path) , _istream("." + path)
{
	if (_istream.is_open())
	{
		_code = "200 OK";
	}
	else
	{
		_code = "404 not found";
		_istream.close();
		_istream.clear();
		_istream.open("404.html");
	}
	_initFile();
	_makeResponse();
}

void Response::_makeResponse()
{
	if (_code.compare(0, 3, "200") == 0)
	{
		_response =
		"HTTP/1.1" + _code + "\r\n"
		"Content-Type: " + _type + "\r\n"
		"Content-Length: " + _ssSize.str() + "\r\n"
		"\r\n" + _file;
	}
	else if (_code.compare(0, 3, "404") == 0)
	{
		_response =
		"HTTP/1.1" + _code + "\r\n"
		"Content-Type: " + _type + "\r\n"
		"Content-Length: " + _ssSize.str() + "\r\n"
		"\r\n" + _file;
	}

}

std::string Response::str()
{
	return (_response);
}

std::string Response::size()
{
	return (_ssSize.str());
}

Response::~Response()
{

}
