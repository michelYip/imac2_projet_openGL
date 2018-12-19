#ifndef _INCORRECT_SAVING_FILE_ 
#define _INCORRECT_SAVING_FILE_

#include "exceptions/Game_exception.hpp"
#include <iostream>

class Incorrect_saving_file : public Game_exception
{
private:
	std::string _filename;	
public:
	Incorrect_saving_file(const std::string &filename, const std::string &file, const int line)
	:Game_exception("Incorrect_saving_file throwed for ["+filename+"] file", file, line),_filename(filename){}
	~Incorrect_saving_file() = default;

};


#define INCORRECT_SAVING_FILE(filename) Incorrect_saving_file(filename, __FILE__, __LINE__);


#endif
