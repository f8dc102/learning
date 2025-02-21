degree = float(input("섭씨 온도 입력 : "))
fahrenheitExact = degree * 9 / 5 + 32
fahrenheitLessExact = degree * 2 + 30 

print(f"정확 변환 결과 : {fahrenheitExact:5.2f}F")
print(f"약식 변환 결과 : {fahrenheitLessExact:5.2f}F")
print(f"두개 공식 차이 : {fahrenheitExact - fahrenheitLessExact:6.2f}F")
