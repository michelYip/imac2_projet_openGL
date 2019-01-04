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
	Player _player; ///< Player of the game
	//view must be before world to init glew
	View _view; ///< View that print every world element 
	World _world; ///< World that contain every element of the game, can be considered as the model 


public:
	Game();
	~Game() = default;


	/// \brief Launch the window and the main loop
	/// \param execName: Name of the executed file. Supposed to be argv[0] of the main
	void run(char* execName);


private: 
	/// \brief  Select a player and load him into _player
	/// \return  The player selected to play 
	Player selectSavedPlayer() const;


};

#endif