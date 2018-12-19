#include "Game.hpp"

#include <algorithm>
#include "exceptions/Unreachable_file.hpp"
#include "ObjLoader.hpp"


void Game::init(){
	std::cout << "________________________________" << std::endl << "GAME INIT STARTING..." << std::endl;
	_player = selectSavedPlayer();
	_world = World();
	
	std::cout << _player << std::endl;

	_player.addUnlockedSkins(Skin("test1",50,"test1.texture"));
	_player.addUnlockedSkins(Skin("test2",10,"test2.texture"));
	try{
		_player.save("player_1");
		std::cout << Player::load("player_1") << std::endl;
	}catch(Unreachable_file &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "GAME INIT DONE." << std::endl << "________________________________" << std::endl;
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