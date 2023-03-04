import numpy as np
import matplotlib.pyplot as plt

# Create variables with the constant values in the equation
u = 2510
M = 2.8 * (10 ** 6)
m = 13.3 * (10 ** 3)
g = 9.81
v = 335


# Define f(t) using contants above
def f(t):
    return u * np.log(M / (M - (m * t))) - g * t - v


# Define df(t), the derivate of f(t) above
def df(t):
    h = 1e-5
    return (f(t + h) - f(t)) / h


def plot_function():
    """ Plots the function f(t) using x values in [0, 150]
        and saves the plot in file rocket.png
    """

    # x-axis is from 0 to 150
    x = np.linspace(0, 150, 151)
    # Compute the y =-axis
    y = f(x)

    # Set labels
    plt.xlabel("t")
    plt.ylabel("f(t)")
    # Enable grid
    plt.grid()
    # Plot the graph
    plt.plot(x, y)
    # Save image to rocket.png
    plt.savefig("rocket.png")
    plt.show()


def find_root():
    """ Returns root of f(t) using Newton-Raphson method"""
    x0 = 20
    tolerance = 10 ** (-9)
    for i in range(100):
        if abs(f(x0)) < tolerance:
            return x0
        else:
            x0 = x0 - f(x0) / df(x0)
    return x0


if __name__ == "__main__":
    print(f(0))  # -335.0
    print(df(0))  # 2.112499999999999
    plot_function()  # Saves the plot in rocket.png
    print("Rocket reaches the speed of sound at t = ", find_root())  # 70.87797226808105
