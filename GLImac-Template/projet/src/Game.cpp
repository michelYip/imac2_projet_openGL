#include "Game.hpp"

#include <algorithm>
#include <ctime>
#include "exceptions/Unreachable_file.hpp"

void Game::init(){
	std::cout << "________________________________" << std::endl << "GAME INIT STARTING..." << std::endl;
	_player = selectSavedPlayer();
	
	std::cout << _player << std::endl;

	_player.addUnlockedSkins(Skin("test1",50,"test1.texture"));
	_player.addUnlockedSkins(Skin("test2",10,"test2.texture"));
	_world.createMap("01.ppm");
	_world.initCharacter();
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
    _view.createWindow(applicationPath,_world);

	std::clock_t start = clock();
	std::clock_t end = start;
	float time_interval = 0; 

	while(!_world.coroutine(_view.done(), time_interval)){
		//TODO
		time_interval = float(end - start)/CLOCKS_PER_SEC; 
		start = clock();
		
		_view.waitEvents();
		_view.displayWindow();

		end = clock();
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