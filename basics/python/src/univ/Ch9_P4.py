import os
import time

st1 = "I LOVE YOU"

for i in range(len(st1)):
    rotated = st1[i:] + st1[:i]
    print(rotated)

#   os.system('clear')
    time.sleep(0.1)
