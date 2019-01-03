#ifndef _OBJECT_ 
#define _OBJECT_

#include <iostream>
#include <glimac/BBox.hpp>
#include <glm/glm.hpp>
#include "Collider.hpp"
#include "Mesh.hpp"

#include <string>

class Object
{
protected: 
	Collider _boundingBox;
	glm::vec3 _position;
	Mesh modele3D;

	static const std::string TEXTURE_FILE; 
	static const std::string OBJ_FILE; 

public:
	//CONSTRUCTORS & DESTRUCTORS
	Object()
	:Object(glm::vec3(), Collider())
	{}
	
	//Parameter constructor with a collider
	Object(const glm::vec3 & position, const Collider & boundingBox);

	//Parameter constructor
	Object(const glm::vec3 & position, const glm::vec3 & _lower, const glm::vec3 & _upper);
	
	//Default destructor
	~Object() = default;


	//GETTERS & SETTERS
	//Return the bounding box of the object
	const Collider boundingBox() const {return _boundingBox;} 
	
	//Return the position of the object
	const glm::vec3 position() const {return _position;}

	//OPERATORS

	//Input stream
	friend std::ostream& operator<<(std::ostream &os, const Object &o);

	//Comparison ==
	bool operator==(const Object & other);
};

#endif