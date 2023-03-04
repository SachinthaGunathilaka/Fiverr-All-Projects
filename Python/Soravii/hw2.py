class Pizza:
    def __init__(self, size='M', toppings=set()):
        self.size = size
        self.toppings = toppings

    def __repr__(self):
        return "Pizza (\'" + self.size + "\'," + str(self.toppings) + ")"

    def setSize(self, size):
        self.size = size

    def getSize(self):
        return self.size

    def addTopping(self, topping):
        self.toppings.add(topping)

    def removeTopping(self, topping):
        self.toppings.remove(topping)

    def price(self):
        prices = {'S': [6.25, 0.7], 'M': [9.95, 1.45], 'L': [12.95, 1.85]}

        return prices[self.size][0] + prices[self.size][1] * len(self.toppings)

    def __eq__(self, other):
        if self.size != other.size or len(self.toppings) != len(other.toppings):
            return False

        for topping in self.toppings:
            if topping not in other.toppings:
                return False

        return True


def orderPizza():
    print("Welcome to Python Pizza!")
    size = input("What size pizza would you like (S,M,L): ").upper()

    toppings = set()
    while True:
        topping = input("Type topping to add (or Enter to quit): ")
        if topping.strip() == "":
            break

        toppings.add(topping)

    pizza = Pizza(size, toppings)

    print("Thanks for ordering!")
    print(f"Your pizza costs ${pizza.price()}")
    print(pizza)

