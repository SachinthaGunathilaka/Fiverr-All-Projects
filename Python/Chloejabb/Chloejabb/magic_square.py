import numpy as np


def is_magic_square(matrix):
    """ Checks of given matrix is a magic square or not.

    Args:
        matrix: a 2D NumPy array
    
    Returns: True if matrix is a magic square, otherwise False
    
    Raises: ValueError if matrix is not square, or if matrix size is not odd.
    """

    # If the matrix is not square raise ValueError
    if len(matrix) != len(matrix[0]):
        raise ValueError("Matrix is not square.")

    # If the size of the matrix is not odd raise ValueError
    if len(matrix) % 2 == 0:
        raise ValueError("Matrix size N must be odd.")

    # Calculate sum of the each column
    columns_sum = np.sum(matrix, axis=0)
    # Calculate sum of the each row
    row_sum = np.sum(matrix, axis=1)

    # Concatenate above 2 arrays
    sums = np.append(columns_sum, row_sum)

    # Calculate the sum of main diagonal
    d1_sum = sum(np.diagonal(matrix))
    # Calculate sum of secondary diagonal
    d2_sum = sum(np.diagonal(np.fliplr(matrix)))

    # Generate array with all the sums
    sums = np.append(sums, [d1_sum, d2_sum])

    # If the all values in the sums array are unique return True
    if len(np.unique(sums)) == len(sums):
        return True

    return False


if __name__ == "__main__":
    A = np.array([[25, 24, 23, 22, 21],
                  [10, 9, 8, 7, 20],
                  [11, 2, 1, 6, 19],
                  [12, 3, 4, 5, 18],
                  [13, 14, 15, 16, 17]])

    print(is_magic_square(A))  # True

    B = np.array([[4, 3, 5],
                  [2, 1, 3],
                  [0, 4, 6]])

    print(is_magic_square(B))  # False

    C = np.array([[25, 24, 23],
                  [10, 9, 8]])
    print(is_magic_square(C))
    # ValueError: Matrix is not square.

    D = np.array([[25, 24],
                  [10, 9, ]])
    print(is_magic_square(D))
    # ValueError: Matrix size N must be odd.

    # Because program stops running as soon as exception is raised,
    # you need to comment code above to see the specific error you want.
