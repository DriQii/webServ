#ifndef ASOCKET_CLASS_HPP
#define ASOCKET_CLASS_HPP

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>

class ASocket {

	public :

		ASocket();
		~ASocket();

		virtual int connect() = 0;
		bool isConnected();

	protected :
		sockaddr_in _addr;
		bool		_connected;
		int			_fd;

};

#endif
