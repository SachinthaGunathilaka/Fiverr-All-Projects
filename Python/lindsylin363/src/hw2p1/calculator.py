from operand import getOperand
class Calculator:
    def add(self, num1, num2):
        print(f"{num1} + {num2} = {round(num1 + num2, 2)}")

    def subtract(self, num1, num2):
        print(f"{num1} - {num2} = {round(num1 - num2, 2)}")

    def multiply(self, num1, num2):
        print(f"{num1} * {num2} = {round(num1 * num2, 2)}")

    def divide(self, num1, num2):
        print(f"{num1} / {num2} = {round(num1 / num2, 2)}")

    def chooseOps(self):

        done = False
        while not done:
            print("\n1.Add\n"
                  "2.Subtract\n"
                  "3.Multiply\n"
                  "4.Divide\n"
                  "5.Exit\n")

            choice = input("Choose an operation (1, 2, 3, 4, or 5): ")
            if choice not in ["1", "2", "3", "4", "5"]:
                print("Invalid selection")
                continue
            if choice == "5":
                print("Application terminated")
                break

            operand1 = float(getOperand("Enter the first operand: "))
            operand2 = float(getOperand("Enter the second operand: "))

            if choice == "1":
                self.add(operand1, operand2)

            elif choice == "2":
                self.subtract(operand1, operand2)

            elif choice == "3":
                self.multiply(operand1, operand2)

            elif choice == "4":
                self.divide(operand1, operand2)


if __name__ == '__main__':
    calculator = Calculator()
    calculator.chooseOps()




