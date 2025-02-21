import random

count = 1
userwin = 0
comwin = 0

while count <= 3:
    user = int(input("홀 0, 짝 1 입력: "))
    com = random.randint(0, 1)
    if user == com:
        userwin += 1
        print("사용자 승")
    else:
        comwin += 1
        print("컴퓨터 승")

    count += 1

print(f"userwin = {userwin}, comwin = {comwin}")
