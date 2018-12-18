#ifndef _TRIGGEROBJECT_ 
#define _TRIGGEROBJECT_

#include "Object.hpp"

class TriggerObject : public Object
{
public:
	TriggerObject();
	~TriggerObject();
	
	virtual launchEvent() = 0;
};

#endif