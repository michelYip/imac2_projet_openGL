#include "Skin.hpp"
#include <fstream>
#include <sstream>
#include <string>

std::vector<Skin> Skin::loadSkins(){
	std::ifstream skinsFile;
	skinsFile.open(SKIN_LIST_FILE, std::fstream::in);
	if(!skinsFile.is_open())
		throw UNREACHABLE_FILE(SKIN_LIST_FILE);

	std::vector<Skin> skinsVector;
	char *tmp_line = new char[128];
	
	while(!skinsFile.eof()){
		//Cut file in str_line
		skinsFile.getline(tmp_line,128);
		std::string str_line(tmp_line);
		
		if(str_line.size() != 0 && str_line.at(0) != '#'){
			//Cut str_line in words
			std::stringstream wordStringstream(str_line);
			std::vector<std::string> skinParams;
			
			while(!wordStringstream.eof()){
				//Save words as param of a skin
				std::string str_word; 
				std::getline(wordStringstream,str_word,',');
				skinParams.push_back(str_word);
			}
			
			// Throw if invalid argument numbers
			if(((int)(skinParams.size())) != 3)
				throw new std::invalid_argument("Invalid number of argument given");

			//Add to vector if ok
			skinsVector.push_back(Skin(skinParams.at(0),std::stoi(skinParams.at(1)),skinParams.at(2)));
		}
	}
	skinsFile.close();
	return skinsVector;
}


Skin Skin::load(const std::string &couted_skin){
	Skin skin;
	std::regex skin_name_regex("name:([^,]*)");
	std::regex skin_price_regex("price:([^,]*)");
	std::regex skin_texture_regex("texture:([^,]*)");
	std::smatch param_name;
	std::smatch param_price;
	std::smatch param_texture;
	std::regex_search(couted_skin, param_name, skin_name_regex);
	std::regex_search(couted_skin, param_price, skin_price_regex);
	std::regex_search(couted_skin, param_texture, skin_texture_regex);
	skin.name() = param_name.str().substr(5);
	skin.price() = std::stoi(param_price.str().substr(6));
	skin.texture() = param_texture.str().substr(8);
	return skin;
}
	


std::ostream& operator<<(std::ostream &os, const Skin &s){
	os << "[name:" << s._name << ", price:" << s._price << ", texture:" << s._texture << "]";
	return os;
}

std::ostream& operator<<(std::ostream &os, const std::vector<Skin> &s_list){
		os << "[\n";
	for (int i = 0; i < s_list.size(); ++i){
		Skin s = s_list.at(i);
		os << "[name:" << s._name << ", price:" << s._price << ", texture:" << s._texture << "],\n";
	}
	os << "]";
	return os;
}



//______________________________________PRIVATE________________________________