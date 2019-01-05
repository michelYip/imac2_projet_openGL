#ifndef _BONUS_ 
#define _BONUS_

#include "TriggerObject.hpp"

/// \class Bonus
/// \bried Bonus present on the Map
class Bonus : public TriggerObject
{
protected:
	// virtual const std::string TEXTURE_FILE(){return "";}
	// virtual const std::string OBJ_FILE(){return "";}
public:
	Bonus(){loadMesh();}
	~Bonus() = default
	
};

#endif