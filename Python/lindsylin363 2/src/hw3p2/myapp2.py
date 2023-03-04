import src.library.game as Game


class MyApp2:
    def trigger(self):
        game = Game.Game(100)
        game.startGame()

        while True:
            guess_value = input("What is your guess? ")
            print(game.guessNumber(guess_value))

            if game.isOver():
                break


if __name__ == '__main__':
    myApp2 = MyApp2()
    myApp2.trigger()
