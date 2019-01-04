#include "Game.hpp"

#include <algorithm>
#include "exceptions/Unreachable_file.hpp"

Game::Game(){
	//TODO
	std::cout << "________________________________" << std::endl << "GAME INIT STARTING..." << std::endl;
	_player = selectSavedPlayer();
	
	std::cout << _player << std::endl;

	_player.addUnlockedSkins(Skin("test1",50,"test1.texture"));
	_player.addUnlockedSkins(Skin("test2",10,"test2.texture"));
	_world.createMap("01.ppm");
	try{
		_player.save("player_1");
		std::cout << Player::load("player_1") << std::endl;
	}catch(Unreachable_file &e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << "GAME INIT DONE." << std::endl << "________________________________" << std::endl;
}

void Game::run(char* execName){
	glimac::FilePath applicationPath(execName);
    _view.createWindow(applicationPath,_world);

	while(!_world.coroutine(_view.done())){
		//TODO
		_view.waitEvents();
		_view.displayWindow();
	}
	_view.clearWindow();
}


//______________________________________PRIVATE________________________________


//Ask to select a player 
//@return the player who will play during the next game
Player Game::selectSavedPlayer() const{
	//TODO
	return Player("Test"); 
}