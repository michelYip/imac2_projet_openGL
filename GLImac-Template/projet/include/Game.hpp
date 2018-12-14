#ifndef _GAME_ 
#define _GAME_

#include <iostream>

#include "Player.hpp"
#include "World.hpp"
	
class Game
{
private: 
	Player _player;
	World _world;

public:
	Game();
	~Game();
	
};

#endif