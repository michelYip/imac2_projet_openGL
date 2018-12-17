#include "Skin.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <string>


//@throws std::runtime_error if file cannot be open
//@return vector of skin that are saved in the file
std::vector<Skin> Skin::loadSkins(){
	std::ifstream skinsFile;
	skinsFile.open(SKIN_LIST_FILE, std::fstream::in);
	if(!skinsFile.is_open())
		throw new std::runtime_error("File not found");

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
	
std::ostream& operator<<(std::ostream &os, const Skin &s){
	os << "[name:" << s._name << ", price:" << s._price << ", texture:" << s._texture << "]";
	return os;
}



//______________________________________PRIVATE________________________________