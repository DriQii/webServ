#include <ServerClass.hpp>

Server::Server() : _nbClients(0), _fdLSock(0)
{

}

Server::~Server()
{

}

void	Server::launchListenSocket()
{
	pollfd pnode;

	_fdLSock = _listenSock.connect();
	pnode.fd = _fdLSock;
	pnode.events = POLLIN;
	_pollVec.push_back(pnode);
}

void	Server::_createClient()
{
	ClientSocket *csock = new ClientSocket(_fdLSock);
	pollfd	pollNodeTmp;
	pollNodeTmp.fd = csock->connect();
	pollNodeTmp.events = POLLIN;
	_pollVec.push_back(pollNodeTmp);
	_clientSocks.push_back(csock);
	_nbClients++;
}

void	Server::pollLoop()
{
	poll(&_pollVec[0], _nbClients + 1, 1000);
	for (size_t i = 0; i < _nbClients + 1; i++)
		if (_pollVec[i].revents == POLLIN)
			i == 0 ?  _createClient() : _clientSocks[i-1]->interact();
}
