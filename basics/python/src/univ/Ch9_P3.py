# Check palindrome

str = input("콤마로 구분된 단어 3개 입력: ").split(', ')

for s in str:
    print(f"단어: {s}, 역순: {s[::-1]}, 회문: {s == s[::-1]}")
