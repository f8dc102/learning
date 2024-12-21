import random
import time
import os

wonHorses = [0] * 3

for t in range(3):
    finalLine = random.randrange(100, 141)
    loopSwitch = True
    locHorse = [-9] * 13
    
    while loopSwitch:
        os.system("clear")

        for i in range(13):
            locHorse[i] += random.randrange(9)

            tmp = ' ' * locHorse[i]
            print(f"{tmp} {i}|>")

            tmp = ' ' * finalLine + "    " 
            print(f"{tmp}|")

            if locHorse[i] > finalLine:
                wonHorses[t] = i 
                loopSwitch = False

            time.sleep(0.01)
    
    print(f"{wonHorses[t]}번 말 승!")
    input("Enter를 누르면 다음 말이 움직입니다.")

print(f"{wonHorses[0]}번 말, {wonHorses[1]}번 말, {wonHorses[2]}번 말 승리!")
input("Enter를 누르면 종료합니다.")
