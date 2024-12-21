import random
import time

howMany = 0
slotLoc = [0] * 3 
loopSwitch = True

while loopSwitch:
    howMany += 1

    print()

    for i in range(3):
        slotLoc[i] = random.randrange(1, 10)
        print(f"{slotLoc[i]} ", end = '')
        time.sleep(0.1)

    print()

    if slotLoc[0] == 7 and slotLoc[1] == 7 and slotLoc[2] == 7: 
        print("Jack Pot!!")
        print(f"총 {howMany}번 시도")
        
        loopSwitch = False
        break
    else:
        print("Try again!")
