#ifndef SERVER_HPP
#define SERVER_HPP

#include "ClientSocketClass.hpp"
#include "ListenSocketClass.hpp"
#include "poll.h"

class Server {

	public :

		Server();
		~Server();

		void	launchListenSocket();
		void	pollLoop();

	private :

		ListenSocket				_listenSock;
		std::vector<ClientSocket*>	_clientSocks;
		std::vector<pollfd>			_pollVec;
		size_t						_nbClients;
		int							_fdLSock;
		void						_launchListenSocket();
		void						_createClient();
		void						_pollLoop();
};

#endif
