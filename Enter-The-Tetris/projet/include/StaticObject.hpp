#ifndef _STATICOBJECT_ 
#define _STATICOBJECT_

#include "Object.hpp"


/// \class StaticObject
/// \brief Inert Object that are present in the World
class StaticObject : public Object
{
public:
	//CONSTRUCTORS & DESTRUCTORS

	//Default constructor
	StaticObject();

	//Parameter constructor
	StaticObject(const glm::vec3 & position, const glm::vec3 & _lower, const glm::vec3 & _upper);
	//Copy constructor
	StaticObject(const StaticObject &staticObject);

	//Default destructor
	~StaticObject() = default;
	
};

#endif