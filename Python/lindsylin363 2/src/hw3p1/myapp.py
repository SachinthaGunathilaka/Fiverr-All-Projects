from src.library.shape import Triangle
from src.library.algebra import Min


class MyApp:
    def trigger(self):
        triangle1 = Triangle(5, 4, 3)
        isTriangleText = ""
        if not triangle1.isTriangular():
            isTriangleText += " not"

        isRightTriangle = ""
        if not triangle1.isRightTriangular():
            isRightTriangle = " not"

        end_text = "."
        if triangle1.isTriangular() and triangle1.isRightTriangular():
            end_text = " as well."

        elif (not triangle1.isTriangular()) and (not triangle1.isRightTriangular()):
            end_text = " either."

        print(
            f"The values of 5, 4, 3 could{isTriangleText} be the sides of a triangle and it is{isRightTriangle} a right triangle{end_text}")

        triangle2 = Triangle(2, 1, 3)
        isTriangleText = ""
        if not triangle2.isTriangular():
            isTriangleText += " not"

        isRightTriangle = ""
        if not triangle2.isRightTriangular():
            isRightTriangle = " not"

        print(
            f"The values of 2, 1, 3 could{isTriangleText} be the sides of a triangle and it is{isRightTriangle} a right triangle{end_text}")

        print()
        minFinder = Min()
        minimum = minFinder.min3(9, 6, 7)
        print(f"The min of 9, 6, 7 is {minimum}")

        minimum = minFinder.min5(5, 7, 3, 8, 1)
        print(f"The min of 5, 7, 3, 8, 1 is {minimum}")

        minimum = minFinder.min3(9.5, 6.5, 7.5)
        print(f"The min of 9.5, 6.5, 7.5 is {minimum}")

        minimum = minFinder.min5(5.5, 7.5, 3.5, 8.5, 1.5)
        print(f"The min of 5.5, 7.5, 3.5, 8.5, 1.5 is {minimum}")


if __name__ == '__main__':
    myApp = MyApp()
    myApp.trigger()
