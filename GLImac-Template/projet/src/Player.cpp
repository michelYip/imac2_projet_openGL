#include "Player.hpp"
#include <sys/stat.h>
#include <ctime>
#include <regex>

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
	    saveTime(playerFile);
	    saveUnlockedSkins(playerFile);
	    saveSelectedSkin(playerFile);
	    savePlayer(playerFile);
    }else{

    }
}

Player Player::load(const std::string &filename){
	std::ifstream playerFile;
	playerFile.open(PLAYER_SAVING_FOLDER+filename, std::fstream::in);
	if(!playerFile.is_open())
			throw new std::runtime_error("File not found");

	const int NB_LINES_SAVED = 4;
	
	Player player;
	for (int line_number = 1; line_number <= NB_LINES_SAVED; ++line_number){
		if(playerFile.eof())
			throw new std::runtime_error("Incorrect file");
			
		//Findint parameters in file
		char *tmp_line = new char[128];
		playerFile.getline(tmp_line,128);
		std::string str_line(tmp_line);
		std::smatch param;
	
		std::regex param_regex (": (.*)");
		std::regex_search(str_line, param, param_regex);
		std::string str_param(param.str(1));
		
		//Saving parameters into player
		if(line_number == 4){ 
			std::regex player_name_regex("name:([^,]*)");
			std::regex player_money_regex("money:([^,]*)");
			std::smatch param_name;
			std::smatch param_money;
			std::regex_search(str_param, param_name, player_name_regex);
			std::regex_search(str_param, param_money, player_money_regex);
			std::cout << "NAME: " << param_name.str() << std::endl;
			player.name() = param_name.str().substr(5);
			player.money() = std::stoi(param_money.str().substr(6));
			player.savingFile() = filename;
		}
	}
	return player;
}



//PRIVATES

void Player::saveUnlockedSkins(std::ofstream &file) const{
	file << "Unlocked skins: ";
	for (int i = 0; i < _unlockedSkins.size(); ++i){
		file << _unlockedSkins.at(0) << ",";
	}
	file << std::endl;
}

void Player::saveTime(std::ofstream &file) const{
	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
	file << "Saving time: " << (now->tm_year + 1900) << '/' << (now->tm_mon + 1) << '/'<<  now->tm_mday << " " << now->tm_hour << "h" << now->tm_min << std::endl;
}

void Player::savePlayer(std::ofstream &file) const{
	file << "Player: " << "[name:" << _name << ", money:" << _money << "]";
}

void Player::saveSelectedSkin(std::ofstream &file) const{
	file << "Selected skin: " << _selectedSkin << std::endl;		
}
