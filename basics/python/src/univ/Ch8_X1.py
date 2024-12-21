import os
import time

order = 60

while order > 0 :
    print(f"{order} 통닭 튀긴다.")

    order -= 1
    time.sleep(0.1)

    os.system("clear")

print("60마리 다 튀김")
input("엔터를 누르면 종료됩니다.")
