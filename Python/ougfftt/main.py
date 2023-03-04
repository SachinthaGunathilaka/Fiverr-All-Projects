"""
    This is the game of BattleShip. The game starts with each player secretly placing their
    ships on their board. A ship can be placed either horizontally or vertically on their board.
    Once the players have finished placing their ships, they take turns guessing locations on
    their opponent's board to fire. Their opponent announces whether the shot hits or misses
    their ship and if it is the final hit on their ship, the fact that shot destroyed their ship.
"""

from battleship.Player import Player

"""
    The function to read configuration file

    Parameters:
        filename (string): filename of the configuration file
      
    Returns:
        rows(int): number of rows
        cols(int): number of cols
        ship_details(list) : details of the ships
"""


def readConfigFile(filename):
    f = open(filename)
    lines = f.readlines()

    rows = int(lines[0])
    cols = int(lines[1])
    ships = int(lines[2])
    ship_details = []

    for i in range(ships):
        data = lines[3 + i].split()
        name = data[0]
        size = int(data[1])

        ship_details.append([name, size])

    return rows, cols, ship_details


"""
    Main function

    Parameters:
        None

    Returns:
        None
"""


def main():
    try:
        config_file = input("Please enter the path to the configuration file for this game: ")
        rows, cols, ship_details = readConfigFile(config_file)
        ship_details.sort(key=lambda x: x[0])

        player1_name = input("Player 1, please enter your name: ")
        player2_name = input("Player 2, please enter your name: ")

        player1 = Player(player1_name, rows, cols)
        player1.placeShips(ship_details)

        player2 = Player(player2_name, rows, cols)
        player2.placeShips(ship_details)

        turn = 1
        while True:
            if player1.isGameOver():
                player2.displayAllBoards()
                print(f"{player2_name} won!")
                break

            elif player2.isGameOver():
                player1.displayAllBoards()
                print(f"{player1_name} won!")
                break

            if turn == 1:
                player1.displayAllBoards()
                while True:
                    row, col = player1.getFiringLocation()
                    status, hit_miss = player2.getAttack(player1_name, row, col)
                    player1.launchAttack(row, col, hit_miss)

                    if status:
                        break

                turn = 0

            else:

                while True:
                    player2.displayAllBoards()
                    row, col = player2.getFiringLocation()
                    status, hit_miss = player1.getAttack(player2_name, row, col)
                    player2.launchAttack(row, col, hit_miss)

                    if status:
                        break

                    print("Invalid firing location")

                turn = 1

    except FileNotFoundError:
        print("Configuration file not found")


main()
