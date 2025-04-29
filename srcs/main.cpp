#include "ServerClass.hpp"



int	main(void)
{
	try {
		Server	serv;

		serv.launchListenSocket();
		while (true)
			serv.pollLoop();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
