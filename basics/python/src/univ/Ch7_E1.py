koScore, enScore, mathScore, sciScore = map(int, input("Kor, Eng, Math, Sci Score : ").split(","))
total = koScore + enScore + mathScore + sciScore
avg = total / 4

print(f"총합 : {total}")
print(f"평균 : {avg}")
