#include "Game.hpp"

#include <algorithm>

void Game::init(){
	_player = selectSavedPlayer();
	_world = World();
	// _player.save("player_1");
	std::cout << Player::load("player_1") << std::endl;
}

void Game::run(){
	while(_world.next_frame()){
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