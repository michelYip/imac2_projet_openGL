#ifndef _PLAYER_ 
#define _PLAYER_

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "exceptions/Incorrect_saving_file.hpp"
#include "exceptions/Unreachable_file.hpp"
#include "exceptions/Insufficient_funds.hpp"
#include "Skin.hpp"

const std::string PLAYER_SAVING_FOLDER = "main/saves/";

/// \class Player
/// \brief Create a Player that can be saved and loaded to continue playing even after closing the game
class Player
{
private:
	std::string _name; ///< Name of the player
	unsigned int _money; ///< Total of money 
	std::string _savingFile; ///<  Filename of the saving file
	std::vector<Skin> _unlockedSkins; ///< Skin that can be picked up by the player
	Skin _selectedSkin; ///< Selected Skin of the player applyed to the Character during the Game

public:
	Player()
	:Player("unknown")
	{}

	/// \param name: Name of the player
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

	inline const Skin selectedSkin() const{return _selectedSkin;}
	inline Skin selectedSkin() {return _selectedSkin;}
	
	inline void gainMoney(const unsigned int sum){ _money+=sum; }
	inline void spendMoney(const unsigned int sum){_money-sum >= 0 ? _money-=sum : throw INSUFFICIENT_FUNDS();}
	
	inline const std::vector<Skin> unlockedSkins() const{return _unlockedSkins;}
	inline void addUnlockedSkins(const Skin &skin){return _unlockedSkins.push_back(skin);}
	

	//PUBLICS FUNCTIONS 
	
	/// \brief Load the player saved in the file
	/// \throw Unreachable_file if file can not be open
	/// \returns loaded Player
	static Player load(const std::string &filename);
	
	/// \brief Save the player in a file
	/// \throw Incorrect_saving_file if file does not have all needed informations
	/// \throw Unreachable_file if file can not be openn
	void save(std::string filename) const;			


	//OPERATORS
	friend std::ostream& operator<<(std::ostream &os, const Player &p);

private:
	///brief Save all unlockedSkins into the file
	void saveUnlockedSkins(std::ofstream &file) const;
	
	///brief Save the selected skin
	void saveSelectedSkin(std::ofstream &file) const;
	
	///brief Save the current time in the file 
	void saveTime(std::ofstream &file) const;
	
	///brief Save the datas of the player 
	void savePlayer(std::ofstream &file) const;


};

#endif