#include "ServerClass.hpp"



int	main(void)
{
	try {
		Server	serv;

		serv.launch();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
