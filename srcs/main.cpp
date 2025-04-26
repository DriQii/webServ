#include "ClientSocketClass.hpp"
#include "ListenSocketClass.hpp"


int	main(void)
{
	try {
		ListenSocket lsock;
		ClientSocket csock;

		csock.connect(lsock.getFd());
		csock.interact();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
