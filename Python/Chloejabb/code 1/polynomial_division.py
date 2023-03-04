import numpy as np


def polynomial_division(coefficients, roots):
    ''' Performs repeated division of given polynomial by (x-r) for each root r
    
    Args:
        coefficients: 1D NumPy array containing coefficients of the polynomial
        roots: 1D NumPy array containing roots of the polynomial
        
    Returns: a NumPy array with the coefficients of the polynomial that
             results from the repeated division
    '''

    # Copy coefficients array to copied_coefficients (So the original array will not change)
    copied_coefficients = np.array(coefficients, copy=True)

    # Iterate through each root
    for root in roots:

        # The first element of the result is the first element of the coefficients array
        prev_value = coefficients[0]
        result = np.array([prev_value])

        # Iterate through the copied_coefficients array from 2nd element to 2nd last element
        for i in range(1, len(copied_coefficients) - 1):
            # Calculate next element of the result
            current_value = copied_coefficients[i] + root * prev_value
            result = np.append(result, [current_value])

            # Set the prev value as the current value
            prev_value = current_value

        # Set result array as the next coefficient array
        copied_coefficients = result

    return result


if __name__ == "__main__":
    # P(x) = 3x^4 + 6x^3 - 21x^2 - 24x + 36
    P = np.array([3, 6, -21, -24, 36])
    Q = polynomial_division(P, np.array([-2]))
    print(Q)  # [  3   0 -21  18]

    R = polynomial_division(P, np.array([-2, 1]))
    print(R)  # [  3   3 -18]

    S = polynomial_division(P, np.array([-2, 1, -3]))
    print(S)  # [ 3 -6]

    # P(x) = x^3 - 3x^2 + 3x - 1
    P = np.array([1, -3, 3, -1])
    Q = polynomial_division(P, np.array([1]))
    print(Q)  # [ 1 -2  1]

    R = polynomial_division(P, np.array([1, 1]))
    print(R)  # [ 1 -1]
