class Ship:
    """
        Constructor of the Ship Class

        Parameters
        ----------
            name : string
                Name of the ship
            size : int
                Size of the ship
    """

    def __init__(self, name, size):
        self.name = name
        self.hits = 0
        self.size = size
        self.alive = True
        self.position = [-1, -1]
        self.direction = ''

    """
       The function to set position of the ship

       Parameters:
           row (int): coordinates  
           col (int): coordinates
           direction (Char): orientation of the ship

       Returns:
           None
   """

    def setPosition(self, row, col, direction):
        self.position = [row, col]
        self.direction = direction

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
        self.hits += 1
        if self.hits == self.size:
            print(f"{player} destroyed {defendant}'s {self.name}!")
            self.alive = False
