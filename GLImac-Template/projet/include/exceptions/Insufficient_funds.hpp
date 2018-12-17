#ifndef _INSUFFICIENT_FUNDS_ 
#define _INSUFFICIENT_FUNDS_

#include "exceptions/Game_exception.hpp"

class Insufficient_funds : public Game_exception
{
public:
	Insufficient_funds(){}
	~Insufficient_funds() = default;
	
};

#endif
