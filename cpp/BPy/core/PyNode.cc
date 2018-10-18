
#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include <BCore/Assert.hh>
#include <BCore/object/Node.hh>
#include <BCore/object/ObjectID.hh>
#include <BCore/object/ObjectManager.hh>
#include <BCore/plugin/PluginSystem.hh>

using namespace bemo;
namespace py = pybind11;

class BPyDagNode : public BDagNode {
public:
    explicit BPyDagNode( ObjectID id ) : BDagNode( id ) { BMO_ERROR << "ctor=" << (void*)this; }
    virtual ~BPyDagNode() { BMO_ERROR << "dtor=" << (void*)this; }
    int execute() override {
        PYBIND11_OVERLOAD_PURE(
                int,
                BPyDagNode,
                execute(),
        );
    }
};

void py_coreGenNode( py::module& m ) {

//    py::class_< BDagNode, BPyDagNode >( m, "CoreNode" )
//            .def(py::init< ObjectID >())
//            .def(py::init<>( [](){ return new BPyDagNode( ObjectManager::instance().acquire() ); } ) )
//            .def("isValid", &BPyDagNode::isValid );
}