#include "Game.hpp"

#include <algorithm>
#include "exceptions/Unreachable_saving_file.hpp"


void Game::init(){
	_player = selectSavedPlayer();
	_world = World();
	try{
		_player.save("player_1");
		std::cout << Player::load("player_1") << std::endl;
	}catch(Unreachable_saving_file &e){
		std::cerr << e.what() << std::endl;
	}
}

void Game::run(const int argc, char** argv){
	glimac::FilePath applicationPath(argv[0]);
    View view;
    view.window(applicationPath);

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