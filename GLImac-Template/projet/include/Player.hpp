#ifndef _PLAYER_ 
#define _PLAYER_

#include <iostream>
#include <vector>
#include "Skin.hpp"

class Player
{
private:
	std::string _name;
	int _money;
	std::string _savingFile;
	std::vector<Skin> _skins;
	Skin _selectedSkin;

public:
	Player()
	:Player("unknown")
	{}

	Player(const std::string &name)
	:_name(name), _money(0)
	{}

	Player(const Player &p)
	:_name(p._name),_money(p._money),_savingFile(p._savingFile),_skins(p._skins),_selectedSkin(p._selectedSkin)
	{}

	~Player() = default;
	
	friend std::ostream& operator<<(std::ostream &os, const Player &p);
};

#endif