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
	Game(){}
	~Game() = default;

	//Select a player and create the world
	void init();

	//Launch and run the game
	void run();


private: 
	// Select a player and load him into _player
	Player selectSavedPlayer() const;


};

#endif