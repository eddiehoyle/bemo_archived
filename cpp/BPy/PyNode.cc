
#include "PyNode.hh"

using namespace bemo;
namespace py = pybind11;

BPyOpenNode::BPyOpenNode() : BDagNode() { BMO_ERROR << "ctor=" << (void*)this; }
BPyOpenNode::~BPyOpenNode() { BMO_ERROR << "dtor=" << (void*)this; }
int BPyOpenNode::execute() {
    PYBIND11_OVERLOAD_PURE(
            int,
            BPyOpenNode,
            execute(),
    )
}

BPyNode::BPyNode( ObjectID id ) : m_id( id ) { BMO_ERROR << "ctor=" << (void*)this; }
BPyNode::~BPyNode() { BMO_ERROR << "dtor=" << (void*)this; }
std::shared_ptr<BPyNode> BPyNode::create( const std::string& type, const std::string& name ) {
    return std::shared_ptr< BPyNode >( new BPyNode( NodeManager::instance().create( type, name ) ) );
}

bool BPyNode::isValid() const { return ObjectManager::instance().exists( m_id ); }

void py_genNode( py::module& m ) {

    py::class_< BPyOpenObject > bpb( m, "OpenObject" );
    bpb.def(py::init<>());

    py::class_< BDagNode, BPyOpenNode >( m, "OpenNode", bpb )
            .def(py::init<>() )
            .def("isValid", &BPyOpenNode::isValid );

    py::class_< BPyNode, std::shared_ptr< BPyNode > >( m, "Node" )
            .def(py::init< ObjectID >() )
            .def_static("create", &BPyNode::create )
            .def("__eq__", &BPyNode::operator== )
            .def("getObjectID", &BPyNode::getObjectID )
            .def("isValid", &BPyNode::isValid );
}