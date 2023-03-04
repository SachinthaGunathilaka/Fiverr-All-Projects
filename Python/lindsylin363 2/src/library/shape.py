class Triangle:
    def __init__(self, side1, side2, side3):
        self.side1 = side1
        self.side2 = side2
        self.side3 = side3

    def isTriangular(self):
        if self.side1 + self.side2 <= self.side3:
            return False

        if self.side1 + self.side3 <= self.side2:
            return False

        if self.side2 + self.side3 <= self.side1:
            return False

        return True

    def isRightTriangular(self):
        if not self.isTriangular():
            return False

        if self.side1 * self.side1 == self.side2 * self.side2 + self.side3 * self.side3:
            return True

        if self.side2 * self.side2 == self.side1 * self.side1 + self.side3 * self.side3:
            return True

        if self.side3 * self.side3 == self.side1 * self.side1 + self.side2 * self.side2:
            return True

        return False
