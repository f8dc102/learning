import time
import os

min = int(input("분 입력: "))
sec = int(input("초 입력: "))

limit = min * 60 + sec

while limit > 0:
    os.system("clear")

    print(f"{min}분 : {sec}초")
    
    sec -= 1

    if sec < 0:
        min -= 1
        sec = 59

    if min < 0:
        break

    time.sleep(1)

    limit -= 1

print("그만 튀겨")
