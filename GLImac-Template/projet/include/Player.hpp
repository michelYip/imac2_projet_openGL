#ifndef _PLAYER_ 
#define _PLAYER_

#include <iostream>
#include <vector>
#include "exceptions/Insufficient_funds.hpp"
#include "Skin.hpp"

class Player
{
private:
	std::string _name;
	unsigned int _money;
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
	

	//GETTERS & SETTER
	inline const std::string name() const{return _name;}
	inline const unsigned int money() const{return _money;}
	inline void gainMoney(const unsigned int sum){ _money+=sum; }
	inline void spendMoney(const unsigned int sum){_money-sum >= 0 ? _money-=sum : throw new Insufficient_funds();}
	inline const std::vector<Skin> skins() const{return _skins;}
	inline const Skin selectedSkin() const{return _selectedSkin;}
	

	//PUBLICS FUNCTIONS 
			


	//OPERATORS
	friend std::ostream& operator<<(std::ostream &os, const Player &p);

};

#endif