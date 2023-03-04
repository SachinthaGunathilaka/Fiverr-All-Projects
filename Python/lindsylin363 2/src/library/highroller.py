class Highroller:
    def validateInput(self, value):
        try:
            value = int(value)
            if value < 0:
                return False

        except:
            return False

        return True

    def getGoal(self):
        while True:
            goal = input("Enter goal: ")
            if self.validateInput(goal):
                return int(goal)

            else:
                print("Invalid")

    def getTrials(self):
        while True:
            trials = input("Enter trials: ")
            if self.validateInput(trials):
                return int(trials)

            else:
                print("Invalid")

    def getNumber(self):
        while True:
            number = input("Enter 1, 2, 5 or 9: ")
            if number in ["1", "2", "5", "9"]:
                return int(number)

            else:
                print("Invalid")

    def getWager(self):
        while True:
            wager = input("wager: ")
            if self.validateInput(wager):
                return int(wager)

            else:
                print("Invalid input")
