#ifndef __LEARNING_GEM5_MY_OBJECT_HH__
#define __LEARNING_GEM5_MY_OBJECT_HH__

#include "params/MyObject.hh"
#include "sim/sim_object.hh"
#include "learning_gem5/byebye_object.hh"

class MyObject : public SimObject
{
    private:
        void processEvent();

	EventFunctionWrapper myEvent;

	Tick latency;
	
	int timesLeft;

	std::string myName;

 	ByeByeObject* myByeObject;

    public:
        MyObject(MyObjectParams *p);
        
	void startup();	
};

#endif //__LEARNING_GEM5_HELLO_OBJECT_HH_
