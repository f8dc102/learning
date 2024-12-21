def check_password(password):
    hasLower = False
    hasUpper = False
    hasDigit = False
    hasSpecial = False

    for char in password:
        if char.islower():
            hasLower = True
        elif char.isupper():
            hasUpper = True
        elif char.isdigit():
            hasDigit = True
        else:
            hasSpecial = True

    return hasLower + hasUpper + hasDigit + hasSpecial >= 3

password = input("사용할 암호 입력: ")

if check_password(password):
    print("사용 가능")
else:
    print("!불가능한 암호!")
