#include "ClientSocketClass.hpp"

ClientSocket::ClientSocket() : _connected(false)
{
	_len = sizeof(_addr);
}

int ClientSocket::connect(int listenFd)
{
	_fd = accept(listenFd, (struct sockaddr *)&_addr, &_len);
	if (_fd == -1)
		throw std::runtime_error("ERROR : Accept failed");
	_connected = true;
	return (_fd);
}

void ClientSocket::interact()
{
	char buffer[4096];
	std::string response =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Content-Length: 22\r\n"
    "\r\n"
    "<h1>Hello, world!</h1>";
	recv(_fd, &buffer, 4096, 0);
	std::cout << buffer << "buffer" << std::endl;
	send(_fd, response.c_str(), std::strlen(response.c_str()), 0);
}

bool ClientSocket::isConnected()
{
	return (_connected);
}

ClientSocket::~ClientSocket()
{
	close(_fd);
}
