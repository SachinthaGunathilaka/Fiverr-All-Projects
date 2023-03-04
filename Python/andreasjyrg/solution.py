class Factory:

    def __init__(self):
        self.cakes = []

    def bake_cake(self, toppings: int, base: int) -> int:
        large = 5
        medium = 2
        small = 1

        count = 0
        while True:
            if toppings >=large and base >= large:
                cake = Cake(large, large)
                self.cakes.append(cake)
                toppings -= large
                base -= large
                count += 1
                continue

            if toppings >=medium and base >= medium:
                cake = Cake(medium, medium)
                self.cakes.append(cake)
                toppings -= medium
                base -= medium
                count += 1

                continue

            if toppings >=small and base >= small:
                cake = Cake(small, small)
                self.cakes.append(cake)
                toppings -= small
                base -= small
                count += 1

                continue

            break

        return count


    def get_last_cakes(self, n: int) -> list:

        if len(self.cakes) < n:
            return []

        result = []
        for i in range(n-1, -1, -1):
            result.append(self.cakes[len(self.cakes) - i - 1])

        return result

    def get_cakes_baked(self) -> list:
        return self.cakes

    def __str__(self):
        if len(self.cakes) <= 1:
            return f"Factory with {len(self.cakes)} cake."

        else:
            return f"Factory with {len(self.cakes)} cakes."



class Cake:

    def __init__(self, base_amount, toppings_amount):
        self.base_amount = base_amount
        self.toppings_amount = toppings_amount

        if base_amount == 1 and toppings_amount == 1:
            self._type = "basic"

        elif base_amount == 2 and toppings_amount == 2:
            self._type = "medium"

        elif base_amount == 5 and toppings_amount == 5:
            self._type = "large"

        else:
            raise WrongIngredientsAmountException()


    @property
    def type(self):
        return self._type

    def __repr__(self):
        return 'Cake(' + self._type + ')'

    def __eq__(self, other):
        if self.base_amount == other.base_amount and self.toppings_amount == other.toppings_amount:
            return True

        return False

    @type.setter
    def type(self, value):
        self._type = value


class WrongIngredientsAmountException(Exception):
    pass
