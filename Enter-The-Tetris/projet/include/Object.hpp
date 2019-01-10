#ifndef _OBJECT_ 
#define _OBJECT_

#include <iostream>
#include <glimac/BBox.hpp>
#include <glm/glm.hpp>
#include "Collider.hpp"
#include "Mesh.hpp"

#include <string>


/// \class Object
/// \bried Abstract class of an object present in the World
class Object
{
protected: 
	Collider _boundingBox;
	glm::vec3 _position;
	Mesh _modele3D;

	void loadMesh(){_modele3D = Mesh(OBJ_FILE(),TEXTURE_FILE());}
	virtual const std::string TEXTURE_FILE(){return "";}
	virtual const std::string OBJ_FILE(){return "cube.obj";}

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
	const Mesh modele3D() const {return _modele3D;}

	//Set the object to a given position
	inline void setPosition(const glm::vec3 & pos) { _position = pos; }

	/// \brief Move an object to the given direction
	/// \param direction: direction in which the object move
	inline void moveObject(const glm::vec3 & direction) { 
		_position += direction; 
		_boundingBox.moveCollider(direction);
	}

	//OPERATORS

	//Input stream
	friend std::ostream& operator<<(std::ostream &os, const Object &o);

	//Comparison ==
	bool operator==(const Object & other);
};

#endif