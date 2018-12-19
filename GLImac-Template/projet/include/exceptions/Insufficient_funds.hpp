#ifndef _INSUFFICIENT_FUNDS_ 
#define _INSUFFICIENT_FUNDS_

#include "exceptions/Game_exception.hpp"

class Insufficient_funds : public Game_exception
{
public:
	Insufficient_funds(const std::string &file, const int line)
	:Game_exception("Insufficient_funds throwed", file, line)
	{}
	
	~Insufficient_funds() = default;
	
};

#define INSUFFICIENT_FUNDS() Insufficient_funds(__FILE__, __LINE__);


#endif
