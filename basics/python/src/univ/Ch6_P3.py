userHeight = int(input("height: "))
userWeight = int(input("weight: "))
howOld = int(input("year: "))

print() # 공백 줄
print("키가 130cm이상인가?", userHeight >= 130)
print("몸무게가 40kg이상인가?", userWeight >= 40)
print("나이가 13세 이상인가?", howOld >= 13)
print("위 사람은 놀이기구를 탈 수 있는가?", \
    userHeight >= 130 and userWeight >= 40 and howOld >= 13)
