#ifndef _GAME_ 
#define _GAME_

#include <iostream>

#include "Player.hpp"
#include "World.hpp"
#include "View.hpp"
	
/// \class Game
/// \brief Create and manage the game
class Game
{
private: 
	Player _player;
	World _world;



public:
	Game(){}
	~Game() = default;

	/// \brief initialization of the game.
	void init();

	/// \brief Launch the window and the main loop
	void run(const int argc, char** argv);


private: 
	/// \brief  Select a player and load him into _player
	/// \return  The player selected to play 
	Player selectSavedPlayer() const;


};

#endif