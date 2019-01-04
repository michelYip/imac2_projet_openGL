#include "Object.hpp"


//Parameter constructor with a collider
Object::Object(const glm::vec3 & position, const Collider & boundingBox)
:_position(position),_boundingBox(boundingBox)
{
	loadMesh();
}

//Parameter constructor
Object::Object(const glm::vec3 & position, const glm::vec3 & _lower, const glm::vec3 & _upper)
:_position(position), _boundingBox(_lower, _upper)
{
	loadMesh();
}

//Input stream
std::ostream& operator<<(std::ostream & os, const Object &o){
	os << "position: [" << o._position.x << ", " << o._position.y 
		<< ", " << o._position.z << "]" << ", bounding_box: " << o._boundingBox;
	return os;
}

//Comparison ==
bool Object::operator==(const Object & other){
	return (_boundingBox == other._boundingBox) 
		&& (_position == other._position);
}

