import random

user = int(input("60만점부터 시작!! 1~20 선택: "))
point = 60
count = 1

while True:
    computer = random.randint(1, 20)
    
    if user != computer:
        count += 1
        point -= count
        print(f"행운 수 {computer:2d} {count}점 사라짐    {point}만점")

    if user == computer:
        break;

print(f"\n오늘은 {point}만점!")

