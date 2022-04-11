//
// Created by fabian on 11.04.22.
//

/*
 * Bindings of the function invert_matrix() using pybind11.
 * Compile with:
 * >> g++ -O3 -I libraries/ -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) invertMatrixPybind.cpp -o invertMatrix$(python3-config --extension-suffix)
 */

#include "pybind11/pybind11.h"
#include "pybind11/eigen.h"

namespace py = pybind11;

#include "invertMatrix.h"

// Create binding for invertMatrix
PYBIND11_MODULE(invertMatrix, m) {
    m.doc() = "Performs matrix inversion using Eigen.";
    m.def("invert_matrix", &invertMatrix, "Solves a linear system.");
}


