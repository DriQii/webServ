#include "RequestClass.hpp"

Request::Request()
{
	std::memset(_buffer, 0, 4096);
}

Request::~Request()
{

}

void	Request::receive(int fd)
{
	size_t	pos = 0;
	size_t	next = 0;
	size_t	mid	= 0;

	recv(fd, &_buffer, 4096, 0);
	_requestStr = _buffer;

	next = _requestStr.find(' ');
	pos = next + 1;

	_requestMap["type"] = _requestStr.substr(0, next);
	next = _requestStr.find(' ', pos);
	_requestMap["path"] = _requestStr.substr(pos, next - pos);
	next = _requestStr.find("\r\n", next) + 2;
	
	while (true)
	{
		pos = next;
		next = _requestStr.find("\r\n", pos) + 2;
		mid = _requestStr.find(':', pos);
		if (next == 1)
			break;
		_headers[_requestStr.substr(pos, mid - pos)] = _requestStr.substr(mid + 2, next - mid - 4);
	}
}

void Request::show()
{
	std::cout << "----REQUEST----\n"
	<< "TYPE : " << _requestMap["type"]
	<< "\nPATH : " << _requestMap["path"]
	<< "\n---HEADERS----"
	<< "\nHost : " << _headers["Host"]
	<< "\nAccept : " << _headers["Accept"]
	<< "\n--------------\n" << std::endl;

}
void Request::show(std::string arg)
{
	std::cout << arg << " : " << _requestMap[arg] << std::endl;
}

