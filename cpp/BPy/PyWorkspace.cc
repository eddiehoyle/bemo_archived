
#include <BCore/workspace/Workspace.hh>

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

using namespace bemo;
namespace py = pybind11;

void py_genWorkspace( py::module& m ) {

    py::class_< Workspace >( m, "Workspace" )
            .def(py::init<>())
            .def_static( "create", &Workspace::create );

//    py::class_< BPyNode, std::shared_ptr< BPyNode > >( m, "Node" )
//            .def(py::init< ObjectID >() )
//            .def("__eq__", &BPyNode::operator== )
//            .def("getObjectID", &BPyNode::getObjectID )
//            .def("isValid", &BPyNode::isValid );
}