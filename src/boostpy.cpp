#include <boost/python.hpp>
#include <stdio.h>

namespace bp = boost::python;

namespace boostpy {
const std::string hello() {
    return "Hello, World from C++!";
}

bool EIGENPY_DLLAPI sharedMemory() { return true; }

BOOST_PYTHON_MODULE(boostpy) {
    // using namespace boost::python;

    PySys_WriteStdout("--------------------------------boostpy\n");
    printf("---------------------boostpy-1\n");

    bp::def("hello", hello);
printf("---------------------boostpy-2\n");

    bp::def("sharedMemory", (bool (*)())sharedMemory,
          "Status of the shared memory when converting from Eigen to Numpy.\n"
          "If True, the memory is shared when converting an Eigen::Matrix to a "
          "numpy.array.\n"
          "Otherwise, a deep copy of the Eigen::Matrix is performed.");
    printf("---------------------boostpy-2\n");
}
}