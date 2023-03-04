# Recursive method to calculate the determinant of a matrix
def determinant(matrix):

    # base case (Find determinant of 2 * 2 matrix)
    if len(matrix) == 2:
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]

    # Calculate determinant recursively
    result = 0
    multiplier = 1
    # Iterate through each element in the first row of the matrix
    for index in range(len(matrix[0])):
        # call determinant_helper method to get another matrix called minor
        minor = determinant_helper(matrix, index)
        result += multiplier * matrix[0][index] * determinant(minor)

        # change the value of multiplier
        if multiplier == 1:
            multiplier = -1
        else:
            multiplier = 1

    return result


# determinant helper method
def determinant_helper(matrix, flag):

    # This will return another matrix
    new_matrix = []
    for i in range(1, len(matrix)):
        new_matrix.append([])
        for j in range(len(matrix)):
            if j == flag:
                continue
            new_matrix[-1].append(matrix[i][j])

    return new_matrix


# Test the program
matrix_3 = [[3, 2, 5], [1, 2, 4], [7, 6, 9]]
matrix_4 = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
matrix_5 = [[1, 3, 5, 2, 1], [5, 4, 3, 2, 1], [9, 8, 7, 6, 5], [3, 2, 2, 3, 1], [6, 5, 5, 4, 3]]


print(determinant(matrix_3))
print(determinant(matrix_4))
print(determinant(matrix_5))