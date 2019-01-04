#include <algorithm>

#include "Map.hpp"

//Default constructor
Map::Map()
:_objectList(), _startPoint(glm::vec2()), _endPoints(), _nextMaps()
{}

//Parameter constructor, load a map and the next ones
Map::Map(const std::string & mapFile, const int & i){
    std::ifstream ppmFile;
    ppmFile.open(MAP_SAVING_FOLDER+mapFile, std::fstream::in);
	if (!ppmFile.is_open())
        throw UNREACHABLE_MAP_FILE(mapFile);
	char * tmp_line = new char[128];
	
	//Check ppm version
	ppmFile.getline(tmp_line,128);
	std::string str_version(tmp_line);
    
	//Commentary
	ppmFile.getline(tmp_line,128);
	std::string str_comment(tmp_line);

	//Check the ppm size (should be 100x100)
	ppmFile.getline(tmp_line,128);
	std::string str_size(tmp_line);
	
	//Check the color depth of the pixels (should be 255)
	ppmFile.getline(tmp_line,128);
	std::string str_color_depth(tmp_line);
	float r, g, b;
	for (int col = 0; col < MAP_SIZE; col++){
        for (int row = 0; row < MAP_SIZE; row++){
			if (ppmFile.eof()){
				throw INCORRECT_MAP_FILE(mapFile);
			}
			ppmFile.getline(tmp_line, 4);
			std::string strR(tmp_line);
			r = std::stoi(strR)/HEIGHT_RATIO_PPM;
			ppmFile.getline(tmp_line, 4);
			std::string strG(tmp_line);
			g = std::stoi(strG)/HEIGHT_RATIO_PPM;
			ppmFile.getline(tmp_line, 4);
			std::string strB(tmp_line);
			b = std::stoi(strB)/HEIGHT_RATIO_PPM;

			if (g >= START_MIN && b >= START_MIN && g <= START_MAX && b <= START_MAX)
				_startPoint = glm::vec2(row, col);
			if (g >= END_MIN && b >= END_MIN && g < END_MAX && b < END_MAX){
				_endPoints.push_back(glm::vec2(row,col));
				if (i <= 0)
					_nextMaps.push_back(Map(mapFile, i - 1));
			}
			if (!(r == 0 && g == 0 && b == 0))
				addObject(Obstacle(row, col, -1, 1));
			if (g < END_MIN && b < END_MIN)
				createObject(row, col, g, b);
        }
    }
}

//Create an object from a pixel
void Map::createObject(const int & col, const int & row, const float & g, const float & b){
	if (g > 0){
		if (g <= OBSTACLE_GROUNDED_THRESHOLD)
			addObject(Obstacle(row, col, 0, g));
		if (g > OBSTACLE_GROUNDED_THRESHOLD && g <= OBSTACLE_AIRBORN_THRESHOLD){
			addObject(Obstacle(row, col, OBSTACLE_FLOAT_HEIGHT, g - OBSTACLE_HEIGHT_MARGIN));
		}
	}
	//Add coin and bonus/malus
	if (b > 0){

	}
}


//Add an object to the object list
void Map::addObject(const Object & obj){
    _objectList.push_back(obj);
}

//Remove an object from the object list
void Map::removeObject(const Object & obj){
    _objectList.erase(std::remove(_objectList.begin(), _objectList.end(), obj), _objectList.end());
}

//Print the starting point and the end point of the map
void Map::printExtremity(){
	std::cout << "Start : " << _startPoint << std::endl;
	for(size_t i = 0; i < _endPoints.size(); i++){
		std::cout << "End " << i << " : " << _endPoints[i] << std::endl;
	}
}

//Print the object list with their position and their bounding box
void Map::printObjectList(){
	for (size_t i = 0; i < _objectList.size(); i++){
		std::cout << _objectList[i] << std::endl;
	}
}