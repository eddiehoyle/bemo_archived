#include "PyNode.hh"

#include <BCore/API.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractNode.hh>

#include <pybind11/pybind11.h>

#include <sstream>

namespace py = pybind11;
using namespace bemo;

// Forward decl
void py_genNodeAbstractNode( py::module& m );

void py_genNode( py::module& m ) {

    py_genNodeAbstractNode( m );
}

void py_genNodeAbstractNode( py::module& m ) {

    py::class_<AbstractNode, PyNode>(m, "AbstractNode")
            .def(py::init<>())
            .def("getID", &AbstractNode::getID)
            .def("getType", &AbstractNode::getType)
            .def("getName", &AbstractNode::getName)
            .def("setName", &AbstractNode::setName)
            .def("isValid", &AbstractNode::isValid)
            .def("execute", &AbstractNode::execute)
            .def("setInput", []( const std::string& name,
                                 py::object data ){})
            .def("__repr__", []( const AbstractNode& n ){
                std::stringstream ss;
                ss << "<AbstractNode(";
                ss << "addr=" << (void*)&n;
                ss << ", id=" << n.getID();
                ss << ")>";
                return ss.str();
            });
}