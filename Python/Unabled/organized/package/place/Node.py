class Node:
    def __init__(self, carriage):
        self.carriage = carriage
        self.next = None

    def __str__(self):
        return f"<{self.carriage}>"
