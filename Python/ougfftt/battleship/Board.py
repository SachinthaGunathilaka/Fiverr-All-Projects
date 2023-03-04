import copy

from battleship.Ship import Ship


class Board:
    """
        Constructor of the Board Class

        Parameters
        ----------
            rows : int
                Number of rows in the board
            cols : int
                Number of cols in the board
            board: list
                entire board
            ships: dict
                all the ships in the board
    """

    def __init__(self, rows, cols):
        self.rows = rows
        self.cols = cols

        self.board = []
        self.ships = {}

    """
       The function to initialize the board

       Parameters:
           None

       Returns:
           None
   """

    def initBoard(self):
        for i in range(self.rows):
            self.board.append(['*'] * self.cols)

    """
       The function to place a ship in the board

       Parameters:
           name (string): name of the ship
           col (int): coordinates
           row (int): coordinates  
           size (int): size of the ship
           direction (Char): orientation of the ship

       Returns:
           status (Boolean): Whether the ship is places successfully or not
   """

    def placeShip(self, name, col, row, size, direction):
        temp_board = copy.deepcopy(self.board)
        for i in range(size):
            if (0 <= row <= self.rows - 1) and (0 <= col <= self.cols - 1):

                if self.board[row][col] != '*':
                    self.board = temp_board
                    # print("Ship overlap with an existing ship")
                    return False

                self.board[row][col] = name
                if direction == 'V':
                    row += 1

                else:
                    col += 1

            else:
                # print("Cannot place the ship in the board")
                self.board = temp_board
                return False

        ship = Ship(name, size)
        ship.setPosition(row, col, direction)

        self.ships[name] = ship
        return True

    """
        The function to display the board

        Parameters:
            None

        Returns:
            None
    """

    def displayBoard(self):
        print(" ", end=' ')
        for i in range(self.cols):
            print(i, end=' ')

        print()

        for i in range(self.rows):
            print(i, end=' ')
            for j in range(self.cols):
                print(self.board[i][j], end=' ')

            print()

    """
        The function to get attack from the other player

        Parameters:
            player (string): name of the attacker
            defendant (string): the player being attacked
            row (int): coordinates
            col (int): coordinates

        Returns:
            status (Boolean): Whether the fire is valid or not 
            hit_miss(Char): Whether fire is a hit or miss 
    """

    def getAttack(self, player, defendant, row, col):
        if (0 <= row <= self.rows - 1) and (0 <= col <= self.cols - 1):

            if self.board[row][col] == 'X':
                return False, 'X'

            ship_name = self.board[row][col]

            if ship_name not in self.ships.keys():
                print(f"{player} missed.")
                self.board[row][col] = 'O'
                return True, 'O'

            self.board[row][col] = 'X'
            print(f"{player} hit {defendant}'s {ship_name}!")
            self.ships[ship_name].getAttack(player, defendant, row, col)
            return True, 'X'

        else:
            return False, '*'

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
        if (0 <= row <= self.rows - 1) and (0 <= col <= self.cols - 1):
            self.board[row][col] = hit_miss

    """
        The function to check whether the game is over

        Parameters:
            None

        Returns:
            game_is_over(Boolean): whether the game is over or not
    """
    def isGameOver(self):
        for ship in self.ships.values():
            if ship.alive:
                return False

        return True
