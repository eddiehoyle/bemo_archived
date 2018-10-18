
#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace py = pybind11;

void py_coreGenNode( py::module& m );

PYBIND11_MODULE(bmocore, m) {
    py_coreGenNode(m);
}