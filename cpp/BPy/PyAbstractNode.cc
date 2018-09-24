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
void py_genNodeImpl( py::module& m, const std::string& type ) {


}

template< template< typename > typename S, typename T >
void py_genNodeImpl2( py::class_< T, S< T > >& cls ) {

    cls.def( "valid", []( T* self )->bool {
        return BMO_NodeManager->exists( self->getID() );
    })
            .def( "connect", []( T* self,
                            const PlugName& sourcePlugName,
                            T* targetNode,
                            const PlugName& targetPlugName ) {

                ConnectionSystem fnConnection( self->getID() );
                fnConnection.connect( sourcePlugName, targetNode->getID(),
                                      targetPlugName );
            } )
            .def( "disconnect", []( T* self,
                                    const PlugName& sourcePlugName,
                                    T* targetNode,
                                    const PlugName& targetPlugName ) {
                ConnectionSystem fnConnection( self->getID() );
                fnConnection.disconnect( sourcePlugName, targetNode->getID(),
                                         targetPlugName );
            } )
            .def( "set_input", []( T* self,
                                   const std::string& name,
                                   const py::object& value ) {
                PlugSystem fnPlug( self->getID() );
                fnPlug.setInput( name, castFromPy( value ) );
            } )
            .def( "set_output", []( T* self,
                                    const std::string& name,
                                    const py::object& value ) {
                PlugSystem fnPlug( self->getID() );
                fnPlug.setOutput( name, castFromPy( value ) );
            } )
            .def( "get_input", []( T* self,
                                   const PlugName& name ) -> py::object {
                PlugSystem fnPlug( self->getID() );
                return castToPy( fnPlug.getInput( name ) );
            } )
            .def( "get_output", []( T* self,
                                    const PlugName& name ) {
                PlugSystem fnPlug( self->getID() );
                return castToPy( fnPlug.getOutput( name ) );
            } )
            .def( "has_input", []( T* self,
                                   const PlugName& name ) -> bool {
                PlugSystem fnPlug( self->getID() );
                return fnPlug.hasInput( name );
            } )
            .def( "has_output", []( T* self,
                                    const PlugName& name ) -> bool {
                PlugSystem fnPlug( self->getID() );
                return fnPlug.hasOutput( name );
            } )
            .def( "get_inputs", []( T* self ) -> std::vector< PlugName > {
                std::vector< PlugName > inputs =
                        BMO_PlugManager->getOwnerPlugNames( self->getID(),
                                                            PlugDirectionPolicy::Input );
                return inputs;
            } )
            .def( "get_outputs", []( T* self ) -> std::vector< PlugName > {
                std::vector< PlugName > outputs =
                        BMO_PlugManager->getOwnerPlugNames( self->getID(),
                                                            PlugDirectionPolicy::Output );
                return outputs;
            } )
            .def( "__repr__", []( T* node ) {
                AbstractNode* bNode = BMO_NodeManager->find( node->getID() );
                std::stringstream ss;
                ss << "<Node(";
                ss << "name='" << bNode->getName();
                ss << "', type=" << bNode->getType();
                ss << ", id=" << bNode->getID();
                ss << ", addr=" << ( void* )node;
                ss << ")>";
                return ss.str();
            } );

}

void py_genNodeAbstractNode( py::module& m ) {


    py::class_< PyNode, std::unique_ptr< PyNode, py::nodelete > > node( m, "PyNode" );
    node.def( py::init<>() );

    py::class_< PyProxyNode, std::shared_ptr< PyProxyNode > > proxyNode( m,
                                                                         "PyProxyNode" );
    proxyNode.def( py::init< ObjectID >() );

    /// TODO Fix this
    py_genNodeImpl2< PyNode, std::unique_ptr< PyNode, py::nodelete > >( node );
    py_genNodeImpl2< PyProxyNode, std::shared_ptr< PyProxyNode > >( proxyNode );
}