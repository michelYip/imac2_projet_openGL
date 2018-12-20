#ifndef _UNREACHABLE_FILE_ 
#define _UNREACHABLE_FILE_

#include "exceptions/Game_exception.hpp"
#include <iostream>



class Unreachable_file : public Game_exception
{
private:
	std::string _filename;	
public:
	Unreachable_file(const std::string &filename, const std::string &file, const int line)
	:Game_exception("Unreachable_file throwed for ["+filename+"] file", file, line), _filename(filename)
	{}
	
	~Unreachable_file() = default;

};

#define UNREACHABLE_FILE(filename) Unreachable_file(filename,  __FILE__, __LINE__);

#endif
