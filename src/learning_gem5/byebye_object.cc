#include "learning_gem5/byebye_object.hh"

#include "debug/MyDebug.hh"
#include "sim/sim_exit.hh"

ByeByeObject::ByeByeObject(ByeByeObjectParams *params) :
    SimObject(params), event(*this), bandwidth(params->write_bandwidth),
    bufferSize(params->buffer_size), buffer(nullptr), bufferUsed(0)
{
    buffer = new char[bufferSize];
    DPRINTF(MyDebug, "Created the byebye object\n");
}

ByeByeObject::~ByeByeObject()
{
    delete[] buffer;
}

void
ByeByeObject::processEvent()
{
    DPRINTF(MyDebug, "Processing the event!\n");
    fillBuffer();
}

void
ByeByeObject::sayByeBye(std::string other_name)
{
    DPRINTF(MyDebug, "Saying byebye to %s\n", other_name);

    message = "ByeBye " + other_name + "!! ";

    fillBuffer();
}

void
ByeByeObject::fillBuffer()
{
    // There better be a message
    assert(message.length() > 0);

    // Copy from the message to the buffer per byte.
    int bytes_copied = 0;
    for (auto it = message.begin();
         it < message.end() && bufferUsed < bufferSize - 1;
         it++, bufferUsed++, bytes_copied++) {
        // Copy the character into the buffer
        buffer[bufferUsed] = *it;
    }

    if (bufferUsed < bufferSize - 1) {
        // Wait for the next copy for as long as it would have taken
        DPRINTF(MyDebug, "Scheduling another fillBuffer in %d ticks\n",
                bandwidth * bytes_copied);
        schedule(event, curTick() + bandwidth * bytes_copied);
    } else {
        DPRINTF(MyDebug, "ByeBye done copying!\n");
        // Be sure to take into account the time for the last bytes
        exitSimLoop(buffer, 0, curTick() + bandwidth * bytes_copied);
    }
}

ByeByeObject*
ByeByeObjectParams::create()
{
    return new ByeByeObject(this);
}
