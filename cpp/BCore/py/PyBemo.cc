
#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include "PyNode.hh"

#include <BCore/Assert.hh>
#include <BCore/object/Graph.hh>
#include <BCore/node/Node.hh>
#include <BCore/node/NodeManager.hh>
#include <BCore/object/ObjectManager.hh>
#include <BCore/plugin/PluginSystem.hh>

#include <sstream>
#include <BCore/node/MultiplyNode.hh>

namespace py = pybind11;
using namespace bemo;

void cpp_init() {
    NodeRegistry::instance().add( "multiply",
                                  multiplyCreate,
                                  multiplyLayout);
}


void py_genNode( py::module& );
void py_genSystem( py::module& );
void py_genEnum( py::module& );


std::shared_ptr<BPyNode> cpp_createNode( const std::string& type, const std::string& name ) {
    return std::shared_ptr<BPyNode>( new BPyNode( NodeManager::instance().create( type, name ) ) );
}

std::vector<std::shared_ptr<BPyNode>> cpp_ls() {
    std::vector<std::shared_ptr<BPyNode>> nodes;
    for ( auto node : NodeManager::instance().list() ) {
        nodes.push_back( std::shared_ptr<BPyNode>( new BPyNode( node->getObjectID() ) ) );
    }
    return nodes;
}

PYBIND11_MODULE(pybemo, m) {

    m.def("init", &cpp_init );

    py_genNode( m );
    py_genSystem( m );
    py_genEnum( m );

    m.def( "create_node",
           &cpp_createNode,
           py::arg("type"), py::arg("name") = "node1" );

    m.def( "ls",
            &cpp_ls );
//
//    m.def("execute", []( BDagNode* nodePtr )->int {
//        return nodePtr->execute();
//    });
//
//
//    m.def( "create_graph",
//           &cpp_createDag< BPyDagGraph >,
//           py::arg("type"), py::arg("name") = "graph1" );
//
//    m.def( "delete", &cpp_deleteObject< BPyDagNode* > );
//    m.def( "delete", &cpp_deleteObject< BPyDagGraph* > );
//
    py::class_<ObjectID>(m, "ObjectID")
            .def(py::init<>())
            .def("__repr__", [](ObjectID* id){
                std::stringstream ss;
                ss << *id;
                return ss.str();
            })
            .def_static("invalid", &ObjectID::invalid);


//    py::class_< BPyDagGraph, std::shared_ptr< BPyDagGraph > >( m, "BPyDagGraph" )
//    py::class_< BPyDagGraph >( m, "BPyDagGraph" )
//            .def(py::init< ObjectID >())
//            .def("isValid", &BPyDagNode::isValid );

//    py::class_< BPyDagObject, std::shared_ptr< BPyDagObject > >( m, "BPyDagObject" )
//            .def(py::init<>());
//            .def( "getObjectID", &BPyDagObject::getObjectID )
//            .def( "getObjectType", &BPyDagObject::getObjectType )
//            .def( "setName", &BPyDagObject::setName )
//            .def( "getName", &BPyDagObject::getName );
//            .def( "connect", &py_connect< T > )
//            .def( "disconnect", &py_disconnect< T > )
//            .def( "set_input", &py_setInput< T > )
//            .def( "set_output", &py_setOutput< T > )
//            .def( "get_input", &py_getInput< T > )
//            .def( "get_output", &py_getOutput< T > )
//            .def( "has_input", &py_hasInput< T > )
//            .def( "has_output", &py_hasOutput< T > )
//            .def( "get_inputs", &py_getInputs< T > )
//            .def( "get_outputs", &py_getOutputs< T > )

}

