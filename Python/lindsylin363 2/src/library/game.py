import random


class Game:
    def __init__(self, ceiling):
        self.ceiling = ceiling
        self.secret = None
        self.is_over = False

    def startGame(self):
        print(f"I am thinking of a secret number between 1 and {self.ceiling}")
        self.secret = random.randint(1, self.ceiling)
        self.is_over = False

    def guessNumber(self, value):

        try:
            value = int(value)
            if value < 0:
                return "Please enter a positive integer"
            if value == self.secret:
                self.is_over = True
                return "You win!"

            if value < self.secret:
                return "Too low"

            return "Too high"

        except:
            return "Please enter an integer"

    def isOver(self):
        return self.is_over
