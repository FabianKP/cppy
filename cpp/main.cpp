#include <iostream>
#include <Eigen/Dense>

#include "invertMatrix.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;


int main() {
    // Let's make a random test matrix and vector.
    MatrixXd A = MatrixXd::Random(3,3);
    VectorXd x = VectorXd::Random(3,1);
    VectorXd b = A * x;
    VectorXd xTilde = invertMatrix(A, b);

    // Compute error = ||x_tilde - x||.
    VectorXd errorVector = xTilde - x;
    double error = errorVector.norm();

    cout << "The error is " << error << endl;

    return 0;
}
