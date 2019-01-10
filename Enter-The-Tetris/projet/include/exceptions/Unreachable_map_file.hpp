#ifndef _UNREACHABLE_MAP_FILE_ 
#define _UNREACHABLE_MAP_FILE_

#include "exceptions/Game_exception.hpp"
#include <iostream>



class Unreachable_map_file : public Game_exception
{
private:
	std::string _filename;	
public:
	Unreachable_map_file(const std::string &filename, const std::string &file, const int line)
	:Game_exception("Unreachable_map_file throwed for ["+filename+"] file", file, line), _filename(filename)
	{}
	
	~Unreachable_map_file() = default;

};

#define UNREACHABLE_MAP_FILE(filename) Unreachable_map_file(filename,  __FILE__, __LINE__);

#endif
