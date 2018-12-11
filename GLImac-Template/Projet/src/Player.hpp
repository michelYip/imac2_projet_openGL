#ifndef _PLAYER_ 
#define _PLAYER_

#include <vector>
#include "Skin.hpp"

class Player
{
private:
	std::string _name;
	std::string _money;
	std::string _savingFile;
	std::vector<Skin> _skins;
	Skin _selectedSkin;

public:
	Player();
	~Player();
	
};

#endif