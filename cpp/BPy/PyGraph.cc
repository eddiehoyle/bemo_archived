#include "PyGraph.hh"

#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace bemo;

void py_genGraph( py::module& m ) {

    py::class_< PyProxyGraph, std::shared_ptr< PyProxyGraph > >( m, "Graph" )
            .def(py::init< ObjectID >())
            .def("connect", [](){})
            .def("disconnect", [](){})
            .def("get_node", [](){})
            .def("add_node", [](){})
            .def("remove_node", [](){});
}