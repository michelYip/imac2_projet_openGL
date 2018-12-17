#include "Player.hpp"
#include <fstream>
#include <sys/stat.h>
#include <ctime>

std::ostream& operator<<(std::ostream &os, const Player &p){
	os << "[name:" << p._name << ", money:" << p._money << ", savingFile:" << p._savingFile << "]";
	return os;
}

void Player::save(std::string filename) const{
	struct stat buf;
    if (!stat((PLAYER_SAVING_FOLDER+filename).c_str(), &buf) != -1){
    	//if file does not exist
		std::ofstream playerFile;
		playerFile.open(PLAYER_SAVING_FOLDER+filename, std::fstream::out);
		if(!playerFile.is_open())
			throw new std::runtime_error("File not found");

		std::time_t t = std::time(0);   // get time now
	    std::tm* now = std::localtime(&t);
	    playerFile << "Creation time: " << (now->tm_year + 1900) << '/' << (now->tm_mon + 1) << '/'<<  now->tm_mday << " " << now->tm_hour << ":" << now->tm_min << std::endl;
	    playerFile << "Last modification time: " << (now->tm_year + 1900) << '/' << (now->tm_mon + 1) << '/'<<  now->tm_mday << " " << now->tm_hour << ":" << now->tm_min << std::endl;
	    playerFile << "Name: " << _name << std::endl;
	    playerFile << "Money: " << _money << std::endl;
	    saveUnlockedSkins(playerFile);
	    playerFile << "Selected skin: " << _selectedSkin << std::endl;		
    }
}

Player Player::load(std::string filename) const{

}


void Player::saveUnlockedSkins(std::ofstream &file) const{
	file << "Unlocked skins: ";
	for (int i = 0; i < _unlockedSkins.size(); ++i){
		file << _unlockedSkins.at(0) << ",";
	}
	file << std::endl;
}