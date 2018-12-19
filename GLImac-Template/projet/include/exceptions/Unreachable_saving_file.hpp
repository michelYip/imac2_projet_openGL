#ifndef _UNREACHABLE_SAVING_FILE_ 
#define _UNREACHABLE_SAVING_FILE_

#include "exceptions/Game_exception.hpp"
#include <iostream>



class Unreachable_saving_file : public Game_exception
{
private:
	std::string _filename;	
public:
	Unreachable_saving_file(const std::string &filename, const std::string &file, const int line)
	:Game_exception("Unreachable_saving_file throwed for ["+filename+"] file", file, line), _filename(filename)
	{}
	
	~Unreachable_saving_file() = default;

};

#define UNREACHABLE_SAVING_FILE(filename) Unreachable_saving_file(filename,  __FILE__, __LINE__);

#endif
