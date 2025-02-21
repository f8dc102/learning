theStr = input("문자열 입력: ")

for i in range(len(theStr) - 1, -1, -1):
    print(theStr[i], end="")

print("\n" + theStr[::-1])
