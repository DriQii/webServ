#include "ListenSocketClass.hpp"

ListenSocket::ListenSocket()
{
	std::memset(&_addr, 0, sizeof(_addr));
	_addr.sin_family = AF_INET;
	_addr.sin_port = htons(8080);
	_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	_fd = socket(AF_INET, SOCK_STREAM, 0);
	int opt = 1; // A VOIR!
	setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	if (_fd == -1)
		throw(std::runtime_error("ERROR : Socket creation failed"));
	if (bind(_fd, (struct sockaddr *)&_addr, sizeof(_addr)) == -1)
		throw std::runtime_error("ERROR : Bind failed");
	if (listen(_fd, 5) == -1)
		throw std::runtime_error("ERROR : Listen failed");
}

int ListenSocket::getFd()
{
	return _fd;
}

ListenSocket::~ListenSocket()
{
	close(_fd);
}
