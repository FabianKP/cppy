#include <iostream>
#include <Dense>

using Eigen::MatrixXd;
using namespace std;

using Eigen::MatrixXd;
using Eigen::VectorXd;
using namespace std;

VectorXd invert_matrix(MatrixXd& A, VectorXd& b) {
    /*
     * Solves the linear system A x = b for x using Eigen's PartialPivLU decomposition.
     */
    // Solve linear system with HouseholderQR-decomposition.
    VectorXd x = A.householderQr().solve(b);
    return x;
}


int main() {
    // Let's make a random test matrix and vector.
    MatrixXd A = MatrixXd::Random(3,3);
    VectorXd x = VectorXd::Random(3,1);
    VectorXd b = A * x;
    VectorXd xTilde = invert_matrix(A, b);

    // Compute error = ||x_tilde - x||.
    VectorXd errorVector = xTilde - x;
    double error = errorVector.norm();

    cout << "The error is " << error << endl;

    return 0;
}
