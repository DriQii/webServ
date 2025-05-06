#ifndef RESPONSE_CLASS_HPP
#define RESPONSE_CLASS_HPP

#include <fstream>
#include <sstream>

class Response {

	public :
		Response(std::string path);
		~Response();

		std::string str();
		std::string size();

	private :
		Response();
		void				_makeResponse();
		void				_initFile();
		std::string			_path;
		std::string			_file;
		std::string			_response;
		std::string			_code;
		std::string			_type;
		std::ifstream		_istream;
		std::ostringstream	_ssFile;
		std::ostringstream	_ssSize;

};

#endif
