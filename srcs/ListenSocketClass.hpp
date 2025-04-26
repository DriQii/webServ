#ifndef LISTEN_SOCKETS_CLASS_HPP
#define LISTEN_SOCKETS_CLASS_HPP

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

class ListenSocket {

	public:
		ListenSocket();
		~ListenSocket();

		int getFd();

	private:
		sockaddr_in _addr;
		int			_fd;
};

#endif
