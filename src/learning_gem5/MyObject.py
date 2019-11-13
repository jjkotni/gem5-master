from m5.params import *
from m5.SimObject import SimObject

class ByeByeObject(SimObject):
    type = 'ByeByeObject'
    cxx_header = "learning_gem5/byebye_object.hh"

    buffer_size     = Param.MemorySize('1kB', "Size of buffer to write good Byes")
    write_bandwidth = Param.MemoryBandwidth('100MB/s', "Bandwidth to fill the buffer")

class MyObject(SimObject):
    type = 'MyObject'
    cxx_header = "learning_gem5/my_object.hh"

    time_to_wait    = Param.Latency('2us', "Time before firing the event" )
    number_of_fires = Param.Int(5, "Number of times to fire the event before good bye" )
    bye_bye_object  = Param.ByeByeObject("A bye bye object")
    name	    = Param.String("Name of the owner")


