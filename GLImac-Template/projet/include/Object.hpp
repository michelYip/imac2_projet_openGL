#ifndef _OBJECT_ 
#define _OBJECT_

#include "Collider.hpp"

class Object
{
private: 
	Collider _boundingBox;
public:
	Object(){}
	~Object() = default;
	
};

#endif