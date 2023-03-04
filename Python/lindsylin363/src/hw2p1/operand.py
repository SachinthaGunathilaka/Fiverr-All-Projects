def getOperand(msg="Enter an operand: "):
    operand = input(msg)
    numericPart = operand
    if numericPart.find("-") == 0:
        numericPart = numericPart.replace("-", "", 1)

    if numericPart.isnumeric():
        return int(operand)

    index = numericPart.find(".")
    if index != -1:
        decimalPart = numericPart[:index]
        floatingPart = numericPart[index + 1:]

        if index == len(numericPart) - 1:
            floatingPart = "0"

        if decimalPart.isnumeric() and floatingPart.isnumeric():
            return float(operand)

    return "Enter a numeric operand"


if __name__ == "__main__":
    print(getOperand())
