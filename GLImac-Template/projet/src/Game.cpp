#include "Game.hpp"

#include <algorithm>

void Game::init(){
	_player = selectSavedPlayer();
	std::cout << _player << std::endl;
	_world = World();
}

void Game::run(){
	while(_world.coroutine()){
		//TODO
	}
}



//______________________________________PRIVATE________________________________


//Ask to select a player 
//@return the player who will play during the next game
Player Game::selectSavedPlayer() const{
	//TODO
	return Player("Test"); 
}