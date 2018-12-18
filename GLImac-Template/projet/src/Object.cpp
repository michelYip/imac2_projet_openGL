#include "Object.hpp"


std::ostream& operator<<(std::ostream &os, const Object &o){
	os << "position: [" << o._position.x << ", " << o._position.y << ", " << o._position.z << "]"; 
	os << ", size: [" << o._size.x << ", " << o._size.y << ", " << o._size.z << "]"; 
	os << ", bounding_box: " << o._boundingBox;
	return os;
}	