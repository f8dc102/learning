for column in range(2, 10) :
    for row in range(1, 10) :
        print(f"{column:-2d} x {row:-2d} = {column * row}")

h = eval(input("Enter diamond's height: "))

print()

for x in range(h):
    print(" " * (h - x), "*" * (2*x + 1))

for x in range(h - 2, -1, -1):
    print(" " * (h - x), "*" * (2*x + 1))

print()
