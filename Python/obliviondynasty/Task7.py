def validateNumber(number):
    if (not number.isnumeric()) or int(number) < 1 or int(number) > 100:
        return False

    return True


def getNumber():
    number = input("Enter number between 1 and 100 : ")
    while not validateNumber(number):
        print("Invalid number")
        number = input("Enter number between 1 and 100 : ")

    return int(number)


def welcome():
    print("---------------------------------")
    print("-------------WELCOME-------------")
    print("---------------------------------\n")


def main():
    number1 = getNumber()
    number2 = getNumber()
    print(f"\nTotal : {number1 + number2}")

main()