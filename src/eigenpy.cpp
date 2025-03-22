#include "eigenpy.h"
#include <boost/python.hpp>

namespace bp = boost::python;
namespace eigenpy {

    bool testMethod() { return true; }

    void enableEigenPy() {
        PySys_WriteStdout("--------------------------------enableEigenPy---1\n");
        bp::def("testMethod", (bool (*)())testMethod, "test");
        PySys_WriteStdout("--------------------------------enableEigenPy---2\n");
    }
}