
import numpy as np

from invertMatrix import invertMatrix


def invert_matrix(a: np.ndarray, b: np.ndarray):
    """
    Solves the linear system Ax=b for x.

    :param a: A square matrix of shape (d,d).
    :param b: A vector of shape (d,).
    :return: The solution, a vector fo shape (d,).
    """
    return invertMatrix(a, b)