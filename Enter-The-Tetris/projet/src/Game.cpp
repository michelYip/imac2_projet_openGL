#include "Game.hpp"

#include <algorithm>
#include <ctime>
#include "exceptions/Unreachable_file.hpp"


void Game::run(char* execName){
	srand(time(NULL));
	std::clock_t start = clock();
	std::clock_t end = start;
	float time_interval = 0;
	
	glimac::FilePath applicationPath(execName);

	/* PRELOADING */
	StartMenu *startmenu = new StartMenu(applicationPath);
	PlayerMenu *playermenu = new PlayerMenu(applicationPath,_player);
	ChangeSkinMenu *changeskinmenu = new ChangeSkinMenu(applicationPath,_player);
	Environment3D *environment3D = new Environment3D(applicationPath,_world,_player);
	SaveMenu *savemenu = new SaveMenu(applicationPath,_player,_world);
	CreatePlayerMenu *createplayermenu = new CreatePlayerMenu(applicationPath, _player ,0);

	//Set start menu as default view rendering
	_view.set_rendering(startmenu);
	_view.createWindow(applicationPath,_world);	

  	//Print loop
	while(!_world.coroutine(_view.done(), time_interval)){
		time_interval = float(end - start)/CLOCKS_PER_SEC; 
		start = clock();
		try{
			_view.waitEvents();
		}
	    catch(const GoToStartMenu &e){ 
			_view.set_rendering(startmenu);
	    }    
	    catch(const GoToSaveMenu &e){
	    	savemenu->player() = _player;
	    	_view.set_rendering(savemenu);
	    }
	    catch(const GoToCreatePlayerMenu &e){ 
	    	createplayermenu->player() = _player;
	    	createplayermenu->playerNum(e.playerNum());
	    	_view.set_rendering(createplayermenu);
	    }
	    catch(const GoToPlayerMenu &e){
		  	_player.gainMoney(_world.earnedMoney());
		  	_world.resetScore();
	    	playermenu->player() = _player;
	    	playermenu->updateScreen();
			_view.set_rendering(playermenu);
	    }
	    catch(const GoToChangeSkinMenu &e){ 
	    	changeskinmenu->player(_player);
	    	changeskinmenu->updateScreen();
	    	_view.set_rendering(changeskinmenu);
	    }
	    catch(const GoTo3DEnvironment &e){ 
	    	_world.createMap("0.ppm");
			_world.initCharacter();
	    	environment3D->player() = _player;
	    	environment3D->updateCharaterTexture();
			_view.set_rendering(environment3D);
	    }    
    	_view.displayWindow();
  		end = clock();
  	}
  	_player.save();

  	delete startmenu;
	delete playermenu;
	delete changeskinmenu;
	delete environment3D;
	delete savemenu;
	delete createplayermenu;
}



