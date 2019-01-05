#ifndef _TRIGGEROBJECT_ 
#define _TRIGGEROBJECT_

#include "Object.hpp"

/// \class TriggerObject
/// \bried Object that can launch and event present in the World 
class TriggerObject : public Object
{
public:
	TriggerObject();
	~TriggerObject();
	
	virtual launchEvent() = 0;
};

#endif