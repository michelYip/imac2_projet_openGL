#include "Game.hpp"

#include <algorithm>
#include "exceptions/Unreachable_file.hpp"

Game::Game(){
	//TODO
	std::cout << "________________________________" << std::endl << "GAME INIT STARTING..." << std::endl;
	

	_player.addUnlockedSkins(Skin("test1",50,"test1.texture"));
	_player.addUnlockedSkins(Skin("test2",10,"test2.texture"));
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
	
	while(!_world.coroutine(_view.done())){
	    try{_view.waitEvents();}
	    catch(const GoToSaveMenu &e){_view.set_rendering(savemenu);}
	    catch(const GoToCreatePlayerMenu &e){ std::cout << "Not yet created option" << std::endl;}
	    catch(const GoToPlayerMenu &e){_view.set_rendering(playermenu);}
	    catch(const GoToChangeSkinMenu &e){ std::cout << "Not yet created option" << std::endl;}
	    catch(const GoTo3DEnvironment &e){ _view.set_rendering(environment3D);}    
		_view.displayWindow();
	}

	delete(startmenu);
	delete(savemenu);
	delete(playermenu);
    
}

