#ifndef _GAME_EXCEPTION_	 
#define _GAME_EXCEPTION_

#include <exception>

class Game_exception : public std::exception
{
public:
	Game_exception(){}
	~Game_exception() = default;
	
};

#endif
