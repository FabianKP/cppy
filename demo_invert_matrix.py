

import numpy as np
from time import time

from invert_matrix import invert_matrix

n = 20    # number of tests
d = 1000      # dimensionality used for testing matrices.
tol = 1e-10     # required accuracy for counting as success.


def solve_with_numpy(a, b, x):
    """
    Solves linear system Ax = b with numpy.linalg.solve.
    """
    x_solved = np.linalg.solve(a, b)
    error = np.linalg.norm(x - x_solved)
    if error > tol:
        print("The error is too large.")

# Create n random (d,d)-matrices.
a_list = [np.random.randn(d, d) for i in range(n)]
# Create n random d-vectors.
x_list = [np.random.randn(d) for i in range(n)]
# Compute the corresponding RHS.
b_list = [a @ x for a, x in zip(a_list, x_list)]



