#include "ClientSocketClass.hpp"
#include "ListenSocketClass.hpp"
#include "poll.h"



int	main(void)
{
	try {
		ListenSocket lsock;
		std::vector<pollfd> pollTest;
		std::vector<ClientSocket*> csocks;
		pollfd	pollNode;

		pollNode.fd = lsock.getFd();
		pollNode.events = POLLIN;
		pollTest.push_back(pollNode);
		while(true)
		{
			poll(&pollTest[0], pollTest.size(), 10000);
			if (pollTest[0].revents == POLLIN)
			{
				ClientSocket *csock = new ClientSocket;
				pollfd	pollNodeTmp;
				pollNodeTmp.fd = csock->connect(lsock.getFd());
				pollNodeTmp.events = POLLIN;
				pollTest.push_back(pollNodeTmp);
				csocks.push_back(csock);
			}
			for (size_t i = 1; i < pollTest.size(); i++)
			{
				//std::cout << "i = "<< i << pollTest[i].fd << " " << csocks[i-1].getFd() << std::endl;
				if (pollTest[i].revents == POLLIN)
							csocks[i-1]->interact();
			}

		}

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
