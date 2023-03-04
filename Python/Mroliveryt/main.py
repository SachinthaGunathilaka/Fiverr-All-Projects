import numpy as np


def isSafeToPlace(matrix, row, col, value):
    for i in range(9):
        if matrix[i][col] == value or matrix[row][i] == value:
            # print("not safe1")
            return False

    grid_x = (row // 3) * 3
    grid_y = (col // 3) * 3

    for i in range(grid_x, grid_x + 3):
        for j in range(grid_y, grid_y + 3):
            if matrix[i][j] == value:
                # print("not safe")

                return False

    # print("safe")
    return True


def sudoku_solver_recursive(matrix, row, col, size):
    if row == size:
        return True

    if col == size:
        return sudoku_solver_recursive(matrix, row + 1, 0, size)

    if matrix[row][col] != 0:
        return sudoku_solver_recursive(matrix, row, col + 1, size)

    for selected_val in range(1, size + 1):
        if isSafeToPlace(matrix, row, col, selected_val):
            matrix[row][col] = selected_val
            if sudoku_solver_recursive(matrix, row, col + 1, size):
                return True

            # print(selected_val)

    matrix[row][col] = 0
    return False


def sudoku_solver(sudoku):
    """
    Solves a Sudoku puzzle and returns its unique solution.

    Input
        sudoku : 9x9 numpy array
            Empty cells are designated by 0.

    Output
        9x9 numpy array of integers
            It contains the solution, if there is one. If there is no solution, all array entries should be -1.
    """

    solved_sudoku = np.full((9, 9), -1)

    for i in range(9):
        for j in range(9):
            if sudoku[i][j] != 0:
                current_val = sudoku[i][j]
                sudoku[i][j] = 0
                if not isSafeToPlace(sudoku, i, j, current_val):
                    sudoku[i][j] = current_val
                    return solved_sudoku
                sudoku[i][j] = current_val

    if sudoku_solver_recursive(sudoku, 0, 0, 9):
        solved_sudoku = sudoku

    return solved_sudoku


# YOUR CODE HERE
matrix = np.array([[1, 0, 4, 3, 8, 2, 9, 5, 6],
                   [2, 0, 5, 4, 6, 7, 1, 3, 8],
                   [3, 8, 6, 9, 5, 1, 4, 0, 2],
                   [4, 6, 1, 5, 2, 3, 8, 9, 7],
                   [7, 3, 8, 1, 4, 9, 6, 2, 5],
                   [9, 5, 2, 8, 7, 6, 3, 1, 4],
                   [5, 2, 9, 6, 3, 4, 7, 8, 1],
                   [6, 0, 7, 2, 9, 8, 5, 4, 3],
                   [8, 4, 3, 0, 1, 5, 2, 6, 9]])

matrix2 = np.array([[8, 5, 2, 9, 7, 6, 2, 4, 3],
                    [6, 7, 9, 1, 4, 3, 2, 8, 5],
                    [0, 3, 1, 2, 5, 8, 7, 6, 9],
                    [3, 1, 4, 5, 2, 7, 8, 9, 6],
                    [7, 6, 8, 3, 9, 1, 4, 5, 0],
                    [9, 2, 5, 6, 0, 0, 3, 7, 1],
                    [5, 4, 3, 8, 6, 2, 9, 1, 7],
                    [1, 9, 7, 4, 3, 5, 0, 2, 8],
                    [2, 8, 6, 7, 1, 9, 5, 3, 4]])

print(sudoku_solver(matrix))
