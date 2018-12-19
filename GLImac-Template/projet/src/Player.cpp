#include "Player.hpp"
#include <sys/stat.h>
#include <ctime>
#include <regex>
#include <string>

std::ostream& operator<<(std::ostream &os, const Player &p){
	os << "[name:" << p._name << ", money:" << p._money << ", savingFile:" << p._savingFile << "]";
	return os;
}

void Player::save(std::string filename) const{
	struct stat buf;
	std::ofstream playerFile;
	playerFile.open(PLAYER_SAVING_FOLDER+filename, std::fstream::out);
	if(!playerFile.is_open())
		throw UNREACHABLE_FILE(PLAYER_SAVING_FOLDER+filename);

    saveTime(playerFile);
    saveUnlockedSkins(playerFile);
    saveSelectedSkin(playerFile);
    savePlayer(playerFile);
    
}

Player Player::load(const std::string &filename){
	std::ifstream playerFile;
	playerFile.open(PLAYER_SAVING_FOLDER+filename, std::fstream::in);
	if(!playerFile.is_open())
			throw UNREACHABLE_FILE(PLAYER_SAVING_FOLDER+filename);

	const int NB_LINES_SAVED = 4;
	
	Player player;
	for (int line_number = 1; line_number <= NB_LINES_SAVED; ++line_number){
		if(playerFile.eof())
			throw UNREACHABLE_FILE(PLAYER_SAVING_FOLDER+filename);
			
		//Findint parameters in file
		char *tmp_line = new char[128];
		playerFile.getline(tmp_line,128);
		std::string str_line(tmp_line);
		std::smatch param;
	
		std::regex param_regex (": (.*)");
		std::regex_search(str_line, param, param_regex);
		std::string str_param(param.str(1));
		
		//Saving parameters into player
		if(line_number == 2){
			//Unlocked skins
			if(str_param.size() != 0){
				str_param.erase(0, 1);
				str_param.erase(str_param.size()-1);
				std::istringstream split(str_param); 
				std::vector<std::string> list_skin_as_str;
				for (std::string each; std::getline(split, each, ']'); list_skin_as_str.push_back(each));
				
				for (int i = 0; i < list_skin_as_str.size(); ++i)
				{
					list_skin_as_str.at(i).erase(0,1);
					std::istringstream split(list_skin_as_str.at(i)); 
					std::vector<std::string> skin_as_str;
					for (std::string each; std::getline(split, each, ','); skin_as_str.push_back(each));
					//Removing everything that is not a param
					skin_as_str.at(0).erase(0,skin_as_str.at(0).find(":")+1);
					skin_as_str.at(1).erase(0,skin_as_str.at(1).find(":")+1);
					skin_as_str.at(2).erase(0,skin_as_str.at(2).find(":")+1);

				
					player.addUnlockedSkins(Skin(skin_as_str.at(0),std::stoi(skin_as_str.at(1)),skin_as_str.at(2)));
				}
			}
		}else if(line_number == 3){
			//Selected skins
			player.selectedSkin() = Skin::load(str_param);
		}else if(line_number == 4){ 
			//Player datas
			std::regex player_name_regex("name:([^,]*)");
			std::regex player_money_regex("money:([^,]*)");
			std::smatch param_name;
			std::smatch param_money;
			std::regex_search(str_param, param_name, player_name_regex);
			std::regex_search(str_param, param_money, player_money_regex);
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
		file << _unlockedSkins.at(i) << ",";
	}
	file << std::endl;
}

void Player::saveTime(std::ofstream &file) const{
	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
	file << "Last saving time: " << (now->tm_year + 1900) << '/' << (now->tm_mon + 1) << '/'<<  now->tm_mday << " " << now->tm_hour << "h" << now->tm_min << std::endl;
}

void Player::savePlayer(std::ofstream &file) const{
	file << "Player: " << "[name:" << _name << ", money:" << _money << "]";
}

void Player::saveSelectedSkin(std::ofstream &file) const{
	file << "Selected skin: " << _selectedSkin << std::endl;		
}
