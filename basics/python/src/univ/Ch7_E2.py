vYear, vMonth, vDay = input("년,월,일 입력 : ").split(",")
vHour, vMin, vSec = input("시,분,초 입력 : ").split(",")

print("현재시간")
print(vYear, vMonth, vDay, sep="-", end="")
print("T", end="")
print(vHour, vMin, vSec, sep=":")
