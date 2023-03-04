def calculate(x, y, op):
    result = 0
    if op == "+":
        result = x + y

    elif op == "-":
        result = x - y

    elif op == "*":
        result = x * y

    elif op == "/":
        if y == 0:
            print("Cannot divide by 0!")
            return
        result = x / y

    elif op == "%":
        result = x % y

    elif op == "**":
        result = x ** y

    # print(f"{x} {op} {y} =")
    print("%d %s %d = %.1f" % (x, op, y, result))


def run_calculator():
    number1 = int(input("Enter number 1: "))
    number2 = int(input("Enter number 2: "))
    op = input("Enter operator: ")

    calculate(number1, number2, op)


def main():
    calculate(7, 3, "+")
    calculate(7, 3, "-")
    calculate(7, 3, "*")
    calculate(7, 0, "/")
    calculate(7, 3, "%")
    calculate(7, 3, "**")

