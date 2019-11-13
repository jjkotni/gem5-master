import m5
from m5.objects import *

root = Root(full_system=False)

root.myObj = MyObject(name='kotnis')
root.myObj.bye_bye_object = ByeByeObject()

m5.instantiate()

print("Beginning Simulation!")
exit_event = m5.simulate()

print("Exited simulation")
#print('Exiting @tick {} because {}' .format(m5.curTick(), exit_event.getCause()))
