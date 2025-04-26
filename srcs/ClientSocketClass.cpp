#include "ClientSocketClass.hpp"

ClientSocket::ClientSocket()
{
	_len = sizeof(_addr);
}

void ClientSocket::connect(int listenFd)
{
	_fd = accept(listenFd, (struct sockaddr *)&_addr, &_len);
	if (_fd == -1)
		throw std::runtime_error("ERROR : Accept failed");
}

void ClientSocket::interact()
{
	char buffer[1096];
	std::string response =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Content-Length: 22\r\n"
    "\r\n"
    "<h1>Hello, world!</h1>";
	recv(_fd, &buffer, 1096, 0);
	std::cout << buffer << std::endl;
	send(_fd, response.c_str(), std::strlen(response.c_str()), 0);
}

ClientSocket::~ClientSocket()
{
	close(_fd);
}
