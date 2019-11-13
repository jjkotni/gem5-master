#ifndef __LEARNING_GEM5_BYEBYE_OBJECT_HH__
#define __LEARNING_GEM5_BYEBYE_OBJECT_HH__

#include <iostream>
#include <string>

#include "params/ByeByeObject.hh"
#include "sim/sim_object.hh"

class ByeByeObject : public SimObject
{
    public:
	ByeByeObject(ByeByeObjectParams *p);
	~ByeByeObject();
	
	void sayByeBye(std::string name);

    private:
	void fillBuffer();
	void processEvent();	

	EventWrapper<ByeByeObject, &ByeByeObject::processEvent> event;
	
	float bandwidth;

	int bufferSize;

	char *buffer;

	std::string message;

	int bufferUsed;
};
#endif
