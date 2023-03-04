import random


class Gambler:
    def __init__(self, stake, goal, trials):
        self.stake = stake
        self.goal = goal
        self.trials = trials

    def roll(self, bets, wins):
        bets = bets
        wins = wins
        for t in range(self.trials):
            cash = self.stake
            while cash > 0 and cash < self.goal:
                bets += 1
                if random.randrange(0, 2) == 0:
                    cash += 1
                else:
                    cash -= 1

            if cash == self.goal:
                wins += 1

        print("Number of trials: " + str(t))
        print("Win rate: " + str(100 * wins // self.trials) + "%")
        print("Avg number of bets: " + str(bets // self.trials))


if __name__ == "__main__":
    g = Gambler(10, 30, 1000)
    g.roll(0, 0)
