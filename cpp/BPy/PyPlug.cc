#include "PyAbstractNode.hh"

#include <BCore/Bemo.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractNode.hh>

#include <pybind11/pybind11.h>

#include <sstream>

namespace py = pybind11;
using namespace bemo;

void py_genPlug( py::module& m ) {

//    py::class_<Plug>(m, "Plug")
//            .def(py::init<>())
//            .def("getID", &Plug::getID)
//            .def("getOwner", &Plug::getOwnerID);
}