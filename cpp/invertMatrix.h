//
// Created by fabian on 11.04.22.
//

#ifndef INVERT_MATRIX_H
#define INVERT_MATRIX_H

#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

VectorXd invertMatrix(MatrixXd& A, VectorXd& b) {
    /*
     * Solves the linear system A x = b for x using Eigen's PartialPivLU decomposition.
     */
    // Solve linear system with HouseholderQR-decomposition.
    VectorXd x = A.householderQr().solve(b);
    return x;
}

#endif //INVERT_MATRIX_H
