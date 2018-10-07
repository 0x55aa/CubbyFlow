import math
import pyCubbyFlow

class MyPhysicsAnimation(pyCubbyFlow.PhysicsAnimation):
    def __init__(self):
        self.init_data = 0
        self.adv_data = 0
        super(MyPhysicsAnimation, self).__init__()

    def onAdvanceTimeStep(self, timeIntervalInSeconds):
        self.adv_data += 1

    def numberOfSubTimeSteps(self, timeIntervalInSeconds):
        return int(math.ceil(timeIntervalInSeconds / 0.02))

    def onInitialize(self):
        self.init_data = 1

def test_inheritance():
    anim = MyPhysicsAnimation()

    anim.isUsingFixedSubTimeSteps = False
    f = pyCubbyFlow.Frame(index=3, timeIntervalInSeconds=0.1)
    anim.update(f)
    assert anim.init_data == 1
    assert anim.adv_data == 20
