
#include "PyNode.hh"

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>


using namespace bemo;
namespace py = pybind11;

BPyOpenNode::BPyOpenNode() : BDagNode() { BMO_ERROR << "ctor=" << (void*)this; }
BPyOpenNode::~BPyOpenNode() { BMO_ERROR << "dtor=" << (void*)this; }
int BPyOpenNode::execute() {
//    PYBIND11_OVERLOAD_PURE(
//            int,
//            BPyOpenNode,
//            execute(),
    return 0;
}

BPyNode::BPyNode( ObjectID id ) : m_id( id ) { BMO_ERROR << "ctor=" << (void*)this; }
BPyNode::~BPyNode() { BMO_ERROR << "dtor=" << (void*)this; }
bool BPyNode::isValid() const { return m_id != ObjectID::invalid(); }

void py_genNode( py::module& m ) {

    py::class_< BDagNode, BPyOpenNode >( m, "OpenNode" )
            .def(py::init<>() )
            .def("isValid", &BPyOpenNode::isValid );

    py::class_< BPyNode, std::shared_ptr< BPyNode > >( m, "Node" )
            .def(py::init< ObjectID >() )
            .def("isValid", &BPyNode::isValid );
}