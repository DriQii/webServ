#ifndef REQUEST_CLASS_HPP
#define REQUEST_CLASS_HPP

#include <map>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>

class Request {

	public :
		Request();
		~Request();

		void show();
		void receive(int fd);
		std::string getRLine(std::string arg);
		std::string getHeader(std::string arg);


	private :
		char	_buffer[4096];
		std::string	_requestStr;
		std::map<std::string, std::string> _requestLine;
		std::map<std::string, std::string> _headers;


};

#endif
