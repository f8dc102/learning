import os
import time

# 60 x 60 
x = 0
y = 0

while x < 60:
    os.system("clear")

    print('  ' * x + "😂")

    x += 1
    time.sleep(0.1)

while y < 60:
    os.system("clear")

    print('\n' * y + '  ' * x + "😂")

    y += 1
    time.sleep(0.1)

while x >= 0:
    os.system("clear")

    print("\n" * y + "  " * x + "😂")

    x -= 1
    time.sleep(0.1)

while y >= 0:
    os.system("clear")

    print("\n" * y + "😂")

    y -= 1
    time.sleep(0.1)

input("Press Enter to continue...")
