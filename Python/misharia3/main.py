import numpy as np

A = np.array([[0, 2, 0, -3],
              [-3, -10, 9, 4],
              [-10, -6, -6, -4],
              [1, 7, -9, 6]])

B = np.array([[0, 2, 0, -3],
              [-3, -10, 9, 4],
              [0, -8, 0, 12],
              [1, 7, -9, 6]])


b = np.array([-20, -141, -14, 203])

det_A = np.linalg.det(A)
det_B = np.linalg.det(B)

# print(det_A, det_B)

x = np.linalg.solve(A, b)
print(x)

A_square = A.dot(A)
print(A_square)