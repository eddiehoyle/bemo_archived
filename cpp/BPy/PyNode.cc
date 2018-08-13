#include "PyNode.hh"

#include <BCore/API.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractNode.hh>

#include <pybind11/pybind11.h>

#include <sstream>

namespace py = pybind11;
using namespace bemo;

// Forward decl
void py_genNodeAbstraceNode( py::module& m );

void py_genNode( py::module& m ) {

    py_genNodeAbstraceNode( m );
}

void py_genNodeAbstractNode( py::module& m ) {
    py::class_<AbstractNode, PyNode>(m, "AbstractNode")
            .def(py::init<>())
            .def_static("objectTypeID", []()->ObjectType{ return AbstractNode::OBJECT_TYPE_ID; } )
            .def("nodeID", &AbstractNode::nodeID)
            .def("typeID", &AbstractNode::typeID)
            .def("isValid", &AbstractNode::isValid)
            .def("execute", &AbstractNode::execute)
            .def("__repr__", []( const AbstractNode& n ){
                std::stringstream ss;
                ss << "<AbstractNode(";
                ss << "addr=" << (void*)&n;
                ss << ", id=" << n.nodeID();
                ss << ", type=" << n.typeID();
                ss << ")>";
                return ss.str();
            });
}