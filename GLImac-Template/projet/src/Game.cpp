#include "Game.hpp"

#include <algorithm>
#include <ctime>
#include "exceptions/Unreachable_file.hpp"

Game::Game(){
	//TODO
	std::cout << "________________________________" << std::endl << "GAME INIT STARTING..." << std::endl;

	//CREATE AND SAVE DEFAULT PLAYER BECAUSE CANNOT CREATE PLAYER FROM THE INTERFACE FOR NOW
	_player.addUnlockedSkins(Skin("test1",50,"test1.texture"));
	_player.addUnlockedSkins(Skin("test2",10,"test2.texture"));
	_player.save("player_1");

	_world.createMap("01.ppm");
	_world.initCharacter();
	
	std::cout << "GAME INIT DONE." << std::endl << "________________________________" << std::endl;
}

void Game::run(char* execName){
	glimac::FilePath applicationPath(execName);
	
	StartMenu *startmenu = new StartMenu(applicationPath);
	SaveMenu *savemenu = new SaveMenu(applicationPath,_player);
	PlayerMenu *playermenu = new PlayerMenu(applicationPath,_player);
	Environment3D *environment3D = new Environment3D(applicationPath,_world,_player);

	_view.set_rendering(startmenu);
	_view.createWindow(applicationPath,_world);

	std::clock_t start = clock();
	std::clock_t end = start;
	float time_interval = 0;
  
	while(!_world.coroutine(_view.done(), time_interval)){
	    time_interval = float(end - start)/CLOCKS_PER_SEC; 
		start = clock();
      	try{_view.waitEvents();}
	    catch(const GoToSaveMenu &e){_view.set_rendering(savemenu);}
	    catch(const GoToCreatePlayerMenu &e){ std::cout << "Not yet created option" << std::endl;}
	    catch(const GoToPlayerMenu &e){_view.set_rendering(playermenu);}
	    catch(const GoToChangeSkinMenu &e){ std::cout << "Not yet created option" << std::endl;}
	    catch(const GoTo3DEnvironment &e){ _view.set_rendering(environment3D);}    
  		_view.displayWindow();
  		end = clock();
  }
	

	delete(startmenu);
	delete(savemenu);
	delete(playermenu);
    
}

