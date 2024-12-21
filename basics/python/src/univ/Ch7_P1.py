# 학번_이름_Ch7_P1.py
num1, num2, num3, num4 = map(int, input("숫자 4개를 입력하세요: ").split())

total = num1 + num2 + num3 + num4
avg = total / 4

print(f"총합 : {total:5d}\n평균 : {avg:.3f}")
