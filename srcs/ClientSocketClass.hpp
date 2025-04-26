#ifndef CLIENT_SOCKETS_CLASS_HPP
#define CLIENT_SOCKETS_CLASS_HPP

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

class ClientSocket {

	public:
		ClientSocket();
		~ClientSocket();

		int connect(int listenFd);
		void interact();
		bool isConnected();

	private:
		sockaddr_in _addr;
		socklen_t 	_len;
		int			_fd;
		bool		_connected;
};

#endif
