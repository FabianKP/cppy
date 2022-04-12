

import numpy as np
from time import time

from invertMatrix import invertMatrix

n = 20    # number of tests
d = 5000      # dimensionality used for testing matrices.
tol = 1e-8     # required accuracy for counting as success.


def solve_with_numpy(a, b, x):
    """
    Solves linear system Ax = b with numpy.linalg.solve.
    """
    x_solved = np.linalg.solve(a, b)
    error = np.linalg.norm(x - x_solved)
    if error > tol:
        print("Numpy: The error is too large.")


def solve_with_eigen(a, b, x):
    x_solved = invertMatrix(a, b)
    error = np.linalg.norm(x - x_solved)
    if error > tol:
        print("Eigen: The error is too large.")


# Create n random (d,d)-matrices.
a_list = [np.random.randn(d, d) for _ in range(n)]
# Create n random d-vectors.
x_list = [np.random.randn(d) for _ in range(n)]
# Compute the corresponding RHS.
b_list = [a @ x for a, x in zip(a_list, x_list)]

# Perform the tests
numpy_times = []
eigen_times = []

counter = 1
for a, b, x in zip(a_list, b_list, x_list):
    print(f"Test {counter}/{n}.")
    t0 = time()
    solve_with_numpy(a, b, x)
    t1 = time()
    solve_with_eigen(a, b, x)
    t2 = time()
    t_np = t1 - t0
    t_eigen = t2 - t1
    numpy_times.append(t_np)
    eigen_times.append(t_eigen)

    counter += 1


t_np_avg = np.mean(np.array(numpy_times))
t_eigen_avg = np.mean(np.array(eigen_times))

print(f"Numpy took on average: {t_np_avg} s.")
print(f"Eigen took on average: {t_eigen_avg} s.")




