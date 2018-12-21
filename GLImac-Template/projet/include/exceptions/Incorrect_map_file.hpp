#ifndef _INCORRECT_MAP_FILE_ 
#define _INCORRECT_MAP_FILE_

#include "exceptions/Game_exception.hpp"
#include <iostream>

class Incorrect_map_file : public Game_exception
{
private:
	std::string _filename;	
public:
	Incorrect_map_file(const std::string &filename, const std::string &file, const int line)
	:Game_exception("Incorrect_map_file throwed for ["+filename+"] file", file, line),_filename(filename){}
	~Incorrect_map_file() = default;

};


#define INCORRECT_MAP_FILE(filename) Incorrect_map_file(filename, __FILE__, __LINE__);


#endif
