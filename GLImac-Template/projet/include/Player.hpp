#ifndef _PLAYER_ 
#define _PLAYER_

#include <iostream>
#include <vector>
#include "exceptions/Insufficient_funds.hpp"
#include "Skin.hpp"
#include <fstream>
#include <sstream>

const std::string PLAYER_SAVING_FOLDER = "Game/save/";


class Player
{
private:
	std::string _name;
	unsigned int _money;
	std::string _savingFile;
	std::vector<Skin> _unlockedSkins;
	Skin _selectedSkin;

public:
	Player()
	:Player("unknown")
	{}

	Player(const std::string &name)
	:_name(name), _money(0)
	{}

	Player(const Player &p)
	:_name(p._name),_money(p._money),_savingFile(p._savingFile),_unlockedSkins(p._unlockedSkins),_selectedSkin(p._selectedSkin)
	{}

	~Player() = default;
	

	//GETTERS & SETTER
	inline const std::string& name() const{return _name;}
	inline std::string& name(){return _name;}
	
	inline const unsigned int& money() const{return _money;}
	inline unsigned int& money(){return _money;}
	
	inline const std::string& savingFile() const{return _savingFile;}
	inline std::string& savingFile(){return _savingFile;}

	inline void gainMoney(const unsigned int sum){ _money+=sum; }
	inline void spendMoney(const unsigned int sum){_money-sum >= 0 ? _money-=sum : throw new Insufficient_funds();}
	inline const std::vector<Skin> unlockedSkins() const{return _unlockedSkins;}
	inline const Skin selectedSkin() const{return _selectedSkin;}
	

	//PUBLICS FUNCTIONS 
	static Player load(const std::string &filename);
	void save(std::string filename) const;			


	//OPERATORS
	friend std::ostream& operator<<(std::ostream &os, const Player &p);

private:
	//Save all unlockedSkins into the file
	void saveUnlockedSkins(std::ofstream &file) const;
	//Save the selected skin
	void saveSelectedSkin(std::ofstream &file) const;
	//Save the current time in the file 
	void saveTime(std::ofstream &file) const;
	//Save the datas of the player 
	void savePlayer(std::ofstream &file) const;


};

#endif