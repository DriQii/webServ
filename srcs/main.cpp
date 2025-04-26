#include "ClientSocketClass.hpp"
#include "ListenSocketClass.hpp"
#include "poll.h"



int	main(void)
{
	try {
		ListenSocket lsock; // socket d'ecoute
		std::vector<ClientSocket*> csocks; // vecteur qui contient chaque socket client
		std::vector<pollfd> pollTest; // vecteur qui contient une structure pollfd par socket client (fd, event, revent)
		pollfd	pollNode; // cree un node de pollfd pour le listen node

		pollNode.fd = lsock.getFd(); // donne le fd de se socket a poll
		pollNode.events = POLLIN; // dit a poll "dit moi quand je peut ecouter ce socket" il le mettra dans revent
		pollTest.push_back(pollNode); // met ce node dans le vecteur
		while(true)
		{
			poll(&pollTest[0], pollTest.size(), 10000); // lance le check de poll (ckeck si les sockets listee dans le vecteur pollTest sont dispo pour levenement demmende par exemple POLLIN pour le premier et si oui il le met dans revent)
			if (pollTest[0].revents == POLLIN) // esce que mon socket decoute est dispo pour l'ecoute
			{
				ClientSocket *csock = new ClientSocket;// malloc un nouveau socket
				pollfd	pollNodeTmp; // cree un nouveau node pour pol
				pollNodeTmp.fd = csock->connect(lsock.getFd()); // donne a pol le fd
				pollNodeTmp.events = POLLIN; // demende a poll de dire quand on peut ecouter dedans
				pollTest.push_back(pollNodeTmp); // ajoute ce node a mon vecteur
				csocks.push_back(csock); // ajoute le socket au vecteur de socket
			}
			for (size_t i = 1; i < pollTest.size(); i++) // boucle tout mon vecteur de pollfd
			{
				if (pollTest[i].revents == POLLIN) // si ce socket est dispo pour la lecture
							csocks[i-1]->interact(); // jinteragis avec lui (pour linstant c pour test mais a ce moment le socket est dispo pour la lecture donc il m'as envoyer quelquechose est dans interact je le lis et je lui repond)
			}
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
