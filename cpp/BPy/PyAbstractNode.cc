#include "PyAbstractNode.hh"

#include <BCore/Bemo.hh>
#include <BCore/object/Plug.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/system/PlugSystem.hh>
#include <BCore/system/ConnectionSystem.hh>

#include <pybind11/pybind11.h>

#include <sstream>
#include <stdexcept>
#include <memory>

namespace py = pybind11;
using namespace bemo;

// Forward decl
void py_genNodeAbstractNode( py::module& m );

void py_genNode( py::module& m ) {

    py_genNodeAbstractNode( m );
}

template< typename T >
bool py_isValid( T* node ) {
    return BMO_NodeManager->exists( node->getID() );
}


template< typename T >
ObjectID py_getID( T* node ) {
    return node->getID();
}

template< typename T >
void py_connect( T* sourceNode,
                 const PlugName& sourcePlugName,
                 T* targetNode,
                 const PlugName& targetPlugName ) {
    ConnectionSystem fnConnection( sourceNode->getID() );
    fnConnection.connect( sourcePlugName,
                          targetNode->getID(),
                          targetPlugName );
}

template< typename T >
void py_disconnect( T* sourceNode,
                    const PlugName& sourcePlugName,
                    T* targetNode,
                    const PlugName& targetPlugName ) {
    ConnectionSystem fnConnection( sourceNode->getID() );
    fnConnection.disconnect( sourcePlugName,
                             targetNode->getID(),
                             targetPlugName );
}

template< typename T >
void py_setInput( T* sourceNode,
                  const std::string& name,
                  const py::object& value ) {
    PlugSystem fnPlug( sourceNode->getID() );
    fnPlug.setInput( name, castFromPy( value ) );
}

template< typename T >
void py_setOutput( T* sourceNode,
                   const std::string& name,
                   const py::object& value ) {
    PlugSystem fnPlug( sourceNode->getID() );
    fnPlug.setOutput( name, castFromPy( value ) );
}


template< typename T >
py::object py_getInput( T* sourceNode,
                        const PlugName& name ) {
    PlugSystem fnPlug( sourceNode->getID() );
    return castToPy( fnPlug.getInput( name ) );
}

template< typename T >
py::object py_getOutput( T* sourceNode,
                         const PlugName& name ) {
    PlugSystem fnPlug( sourceNode->getID() );
    return castToPy( fnPlug.getOutput( name ) );
}

template< typename T >
bool py_hasInput( T* sourceNode,
                  const PlugName& name ) {
    PlugSystem fnPlug( sourceNode->getID() );
    return fnPlug.hasInput( name );
}

template< typename T >
bool py_hasOutput( T* sourceNode,
                   const PlugName& name ) {
    PlugSystem fnPlug( sourceNode->getID() );
    return fnPlug.hasOutput( name );
}

template< typename T >
std::vector< PlugName > py_getInputs( T* sourceNode,
                                      const PlugName& name ) {
    return BMO_PlugManager->getOwnerPlugNames( sourceNode->getID(),
                                               PlugDirectionPolicy::Input );
}

template< typename T >
std::vector< PlugName > py_getOutputs( T* sourceNode,
                                       const PlugName& name ) {
    return BMO_PlugManager->getOwnerPlugNames( sourceNode->getID(),
                                               PlugDirectionPolicy::Output );
}

template< typename T >
std::string py__repr__( T* node ) {
    AbstractNode* bNode = BMO_NodeManager->find( node->getID() );
    std::stringstream ss;
    ss << "<Node(";
    ss << "name='" << bNode->getName();
    ss << "', type=" << bNode->getType();
    ss << ", id=" << bNode->getID();
    ss << ", addr=" << ( void* )node;
    ss << ")>";
    return ss.str();
}


template< typename T, typename... S >
void py_genNodeImpl2( py::class_< T, S... >& cls ) {

    cls.def( "valid", &py_isValid< T > )
            .def( "getID", &py_getID< T > )
            .def( "connect", &py_connect< T > )
            .def( "disconnect", &py_disconnect< T > )
            .def( "set_input", &py_setInput< T > )
            .def( "set_output", &py_setOutput< T > )
            .def( "get_input", &py_getInput< T > )
            .def( "get_output", &py_getOutput< T > )
            .def( "has_input", &py_hasInput< T > )
            .def( "has_output", &py_hasOutput< T > )
            .def( "get_inputs", &py_getInputs< T > )
            .def( "get_outputs", &py_getOutputs< T > )
            .def( "__repr__", &py__repr__< T > );
}

void py_genNodeAbstractNode( py::module& m ) {

    using PyNodeCls = py::class_< PyNode, std::unique_ptr< PyNode, py::nodelete > >;
    using PyProxyNodeCls = py::class_< PyProxyNode, std::shared_ptr< PyProxyNode > >;

    PyNodeCls node( m, "PyNode" );
    node.def( py::init<>() );

    PyProxyNodeCls proxyNode( m, "PyProxyNode" );
    proxyNode.def( py::init< ObjectID >() );

    py_genNodeImpl2< PyNode, PyNodePtr >( node );
    py_genNodeImpl2< PyProxyNode, PyProxyNodePtr >( proxyNode );
}