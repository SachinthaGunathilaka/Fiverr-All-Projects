from battleship.Board import Board


class Player:
    """
        Constructor of the Player Class

        Parameters
        ----------
            name : str
                name of the player
            rows : int
                Number of rows in the board
            cols : int
                Number of cols in the board
    """

    def __init__(self, name, rows, cols):
        self.name = name

        self.board = Board(rows, cols)
        self.board.initBoard()

        self.firingBoard = Board(rows, cols)
        self.firingBoard.initBoard()

    """
        The function to place ships in the board

        Parameters:
            ship_details (list): list containing the details of each ship

        Returns:
            None
    """

    def placeShips(self, ship_details):

        for name, size in ship_details:
            self.displayBoard()

            while True:

                user_dir = input(f"{self.name}, enter the orientation of your {name}, which is {size} long: ").lower()

                direction = ""
                while True:
                    if "horizontally".startswith(user_dir):
                        direction = 'H'
                        break

                    elif "vertically".startswith(user_dir):
                        direction = 'V'
                        break

                    user_dir = input(
                        f"{self.name}, enter the orientation of your {name}, which is {size} long: ").lower()

                row = -1
                col = -1
                while True:
                    try:
                        row_col = input(
                            f"Enter the starting location for your {name}, which is {size} long, in the form row col:").split()
                        row = int(row_col[0])
                        col = int(row_col[1])
                        break

                    except:
                        pass

                status = self.board.placeShip(name, col, row, size, direction)

                if status:
                    break
        self.displayBoard()

    """
        The function to display the placement board

        Parameters:
            None

        Returns:
            None
    """

    def displayBoard(self):
        print(f"{self.name}'s Placement Board")
        self.board.displayBoard()

    """
        The function to get coordinates of the firing location

        Parameters:
            None

        Returns:
            row(int), col(int): coordinates of the firing location 
    """

    def getFiringLocation(self):
        while True:
            try:
                location = input(f"{self.name}, enter the location you want to fire at in the form row col: ").split()
                row = int(location[0])
                col = int(location[1])
                return row, col

            except:
                pass

    """
        The function to get attack from the other player

        Parameters:
            player (string): name of the attacker
            row (int): coordinates
            col (int): coordinates

        Returns:
            status (Boolean): Whether the fire is valid or not 
            hit_miss(Char): Whether fire is a hit or miss 
    """
    def getAttack(self, player, row, col):
        return self.board.getAttack(player, self.name, row, col)

    """
        The function to launch attack to the other player

        Parameters:
            row (int): coordinates
            col (int): coordinates
            hit_miss (Char): Whether fire is a hit or miss 

        Returns:
            None
    """
    def launchAttack(self, row, col, hit_miss):
        self.firingBoard.launchAttack(row, col, hit_miss)

    """
        The function to display placement board and the firing board

        Parameters:
            None

        Returns:
            None
    """
    def displayAllBoards(self):
        print(f"{self.name}'s Firing Board")
        self.firingBoard.displayBoard()
        self.displayBoard()

    """
        The function to check whether the game is over

        Parameters:
            None

        Returns:
            game_is_over(Boolean): whether the game is over or not
    """
    def isGameOver(self):
        return self.board.isGameOver()
