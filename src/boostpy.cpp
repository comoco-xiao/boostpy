#include <boost/python.hpp>
#include "eigenpy.h"

namespace bp = boost::python;
using namespace eigenpy;

namespace boostpy {
const std::string hello() {
    return "Hello, World from C++!";
}

bool sharedMemory() { return true; }

BOOST_PYTHON_MODULE(boostpy) {
    PySys_WriteStdout("--------------------------------boostpy---1\n");
    bp::def("hello", hello);
    PySys_WriteStdout("--------------------------------boostpy---2\n");

    bp::def("sharedMemory", (bool (*)())sharedMemory,
          "Status of the shared memory when converting from Eigen to Numpy.\n"
          "If True, the memory is shared when converting an Eigen::Matrix to a "
          "numpy.array.\n"
          "Otherwise, a deep copy of the Eigen::Matrix is performed.");
    PySys_WriteStdout("--------------------------------boostpy---3\n");
    enableEigenPy();
    PySys_WriteStdout("--------------------------------boostpy---4\n");
}
}