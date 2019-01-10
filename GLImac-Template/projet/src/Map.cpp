#include <algorithm>
#include <random>

#include "Map.hpp"

//Default constructor
Map::Map()
:_objectList(), _startPoint(glm::vec2()), _endPoints(), _nextMaps()
{}

//Default constructor
Map::Map(const Map & other)
:_objectList(other._objectList), _startPoint(other._startPoint), _endPoints(other._endPoints), _nextMaps(other._nextMaps)
{}

//Parameter constructor, load a map and the next ones
Map::Map(const std::string & mapFile, const int & i, const glm::vec2 & start){
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
	for (int row = MAP_SIZE; row > 0; row--){
        for (int col = MAP_SIZE; col > 0; col--){
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
				_startPoint = glm::vec2(col, row) - glm::vec2(INIT_X, INIT_Z) + start;
			if (g >= END_MIN && b >= END_MIN && g < END_MAX && b < END_MAX){
				_endPoints.push_back(glm::vec2(col,row) - glm::vec2(INIT_X, INIT_Z) + start);
			}
			if (!(r == 0 && g == 0 && b == 0))
				addObject(Obstacle(col + start.x - INIT_X, row + start.y - INIT_Z, -1));
			if (g < END_MIN && b < END_MIN)
				createObject(col + start.x - INIT_X, row + start.y - INIT_Z, g, b);
        }
    }
	for (int t = 0; t < _endPoints.size(); t++){
		if (i > 0){
			_nextMaps.push_back(Map(randomMap(), i - 1, start + _endPoints.back() - _startPoint));
		}
	}
	delete tmp_line;		
}

//Create a random map at the end of the track
void Map::appendMaps(){
	if (_nextMaps.empty())
	{
		for (int i = 0; i < _endPoints.size(); i++)
		{
			_nextMaps.push_back(Map(randomMap(), 0, _endPoints[i]));
		}
	}
	else
	{
		for (int j = 0; j < _nextMaps.size(); j++){
			_nextMaps[j].appendMaps();
		}
	}
}

//Create an object from a pixel
void Map::createObject(const int & col, const int & row, const float & g, const float & b){
	int height = 0;
	int altitude = 0;
	if (g > 0){
		if (g <= OBSTACLE_GROUNDED_THRESHOLD){
			height = g;
			altitude = 0;
		}
		if (g > OBSTACLE_GROUNDED_THRESHOLD && g <= OBSTACLE_AIRBORN_THRESHOLD){
			height = g - OBSTACLE_HEIGHT_MARGIN;
			altitude = OBSTACLE_FLOAT_HEIGHT;
		}
		for (int i = 0; i < height; i++){
			addObject(Obstacle(col, row, altitude + i));
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

//Progress in the map
void Map::moveMap(const float & distance){
	if (!_nextMaps.empty()){
		for (int t = 0; t < _nextMaps.size(); t++)
			_nextMaps[t].moveMap(distance);
	}
	for (int i = 0; i < _objectList.size(); i++){
		_objectList[i].moveObject(glm::vec3(0,0,distance));
	}
	for (int i = 0; i < _endPoints.size(); i++){
		_endPoints[i] += glm::vec2(0,distance);
	}
}

//Return the list of object of all maps
std::vector<Object> Map::getAllObjects(const int & i) const {
	if (_nextMaps.empty()){
		return _objectList;
	}
	std::vector<Object> list = _objectList;
	for (int t = 0; t < _nextMaps.size(); t++){
		std::vector<Object> nextList = _nextMaps[t].getAllObjects(i-1);
		list.insert(std::end(list), std::begin(nextList), std::end(nextList));
	}
	return list;
}

std::string Map::randomMap() const{
    int random_number = std::rand() % MAP_NUMBER;
	std::string mapName = std::to_string(random_number);
	mapName += ".ppm";
	return mapName;
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