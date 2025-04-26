#include "ClientSocketClass.hpp"
#include "ListenSocketClass.hpp"
#include "poll.h"

int	main(void)
{
	try {
		ListenSocket lsock;
		ClientSocket csock;

		pollfd pollTest[2];
		pollTest[0].fd = lsock.getFd();
		pollTest[0].events = POLLIN;
		pollTest[1].fd = -1;
		while(true)
		{
			poll(pollTest, 2, 100000);
			if (pollTest[0].revents == POLLIN)
			{
				pollTest[1].fd = csock.connect(lsock.getFd());
				pollTest[1].events = POLLIN;
			}
			if (pollTest[1].revents == POLLIN)
			{
				csock.interact();
			}
		}

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
