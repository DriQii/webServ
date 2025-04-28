#ifndef CLIENT_SOCKETS_CLASS_HPP
#define CLIENT_SOCKETS_CLASS_HPP

#include "ASocketClass.hpp"

class ClientSocket : public ASocket {

	public:
		ClientSocket(int listenFd);
		~ClientSocket();

		int connect();
		void interact();

	private:
		socklen_t 	_len;
		int			_listenFd;
		
};

#endif
