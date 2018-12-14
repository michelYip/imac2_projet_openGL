#include "Game.hpp"


void Game::init(){
	_player = selectSavedPlayer();
	std::cout << _player << std::endl;
	_world = World();
}

void Game::run(){
	while(_world.next_frame()){
		//TODO
	}
}



//______________________________________PRIVATE________________________________

Player Game::selectSavedPlayer() const{
	return Player("Test"); 
}