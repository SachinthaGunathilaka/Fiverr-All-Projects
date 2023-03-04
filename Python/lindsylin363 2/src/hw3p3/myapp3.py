from src.library.gamer import Gambler
from src.library.highroller import Highroller

class MyApp3:
    def trigger(self):
        high_roller = Highroller()
        goal = high_roller.getGoal()
        trials = high_roller.getTrials()
        number = high_roller.getNumber()
        if number == 1:
            print("Gone all in.", end=" ")

        if number == 9:
            print("Quit")
            return
        wager = high_roller.getWager()

        stake = wager / number

        gambler = Gambler(stake, goal, trials)
        gambler.roll(0, 0)


if __name__ == '__main__':
    myapp3 = MyApp3()
    myapp3.trigger()