#include "learning_gem5/my_object.hh"
#include "debug/MyDebug.hh"
#include <iostream>
#include <string>

MyObject::MyObject(MyObjectParams *params): SimObject(params),
myEvent([this]{processEvent();},name())
{ 
    this->latency     = params->time_to_wait;
    this->timesLeft   = params->number_of_fires;
    this->myByeObject = params->bye_bye_object;
    this->myName      = params->name;

    std::cout << "My World! From a SimObject" <<std::endl;
    DPRINTF(MyDebug, "Debug Flag Check\n");
}

MyObject* MyObjectParams::create()
{
    return new MyObject(this);
}

void MyObject::processEvent()
{
    timesLeft--;

    if(timesLeft == 0 )
    {
	DPRINTF(MyDebug, "Done with my events!!\n");
	(*myByeObject).sayByeBye(myName);
    }
    else
    {
	DPRINTF(MyDebug, "Hi! I'm processing an event, %d left\n", timesLeft );
	schedule( myEvent, curTick()+latency );
    };
}

void MyObject::startup()
{
    schedule(myEvent, 200);
}
