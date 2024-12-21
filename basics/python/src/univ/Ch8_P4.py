import random

chipCount = 10
while True:
    computerNum = random.randint(1, 10)
    userNum = random.randint(1, 10)

    batChip = int(input(f"your num = {userNum}, chip = {chipCount}(0은 포기): "))
    print(f"com num = {computerNum}\n")

    if userNum == computerNum:
        chipCount += batChip 
        print(f"사용자 승! chip = {chipCount}\n")
    else:
        chipCount -= batChip

    if batChip == 0 or chipCount <= 0:
        print("게임 초기화!")
        chipCount = 10
        continue
