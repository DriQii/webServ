#include <ClientSocketClass.hpp>

ClientSocket::ClientSocket(int listenFd) : _listenFd(listenFd)
{
	_len = sizeof(_addr);
}

int ClientSocket::connect()
{
	_fd = accept(_listenFd, (struct sockaddr *)&_addr, &_len);
	fcntl(_fd, F_SETFL, O_NONBLOCK);
	if (_fd == -1)
		throw std::runtime_error("ERROR : Accept failed");
	_connected = true;
	return (_fd);
}

void ClientSocket::interact()
{
	char buffer[4096];
	std::memset(buffer, 0, 4096);
	std::string response =
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "Content-Length: 37\r\n"
    "\r\n"
    "<h1>Hello from Webserv My broski</h1>";
	recv(_fd, &buffer, 4096, 0);
	std::cout << buffer << std::endl;
	send(_fd, response.c_str(), std::strlen(response.c_str()), 0);
}

ClientSocket::~ClientSocket()
{
	close(_fd);
}
