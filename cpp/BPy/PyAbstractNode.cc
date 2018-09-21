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

static py::object castToPy( const Variant& var ) {
    bool result;
    py::object value;
    switch ( var.type() ) {
        case VariantType::Long:
            value = py::int_( var.toLong( &result ) );
            break;
        case VariantType::Float:
            value = py::float_( var.toFloat( &result ) );
            break;
        case VariantType::String:
            value = py::str( var.toString( &result ) );
            break;
        case VariantType::Null:
        default:
            value = py::none();
    }
    return value;
}

static Variant castFromPy( const py::object& obj ) {
    Variant value;
    if ( py::isinstance< py::int_ >( obj ) ) {
        value.reset( Variant( obj.cast< long >() ) );
    } else if ( py::isinstance< py::float_ >( obj ) ) {
        value.reset( Variant( obj.cast< float >() ) );
    } else if ( py::isinstance< py::str >( obj ) ) {
        value.reset( Variant( obj.cast< std::string >() ) );
    } else if ( py::isinstance< py::none >( obj ) ) {
    } else {
    }
    return value;
}

void py_genNodeAbstractNode( py::module& m ) {

    py::class_<AbstractNode, PyAbstractNode, std::unique_ptr< AbstractNode, py::nodelete > >(m, "AbstractNode")
            .def(py::init<>())
            .def("getID", &AbstractNode::getID)
            .def("getType", &AbstractNode::getType)
            .def("getName", &AbstractNode::getName)
            .def("setName", &AbstractNode::setName)
            .def("isValid", &AbstractNode::isValid)
            .def("execute", &AbstractNode::execute)
            .def("connect", []( AbstractNode* self,
                                const PlugName& sourcePlugName,
                                AbstractNode* targetNode,
                                const PlugName& targetPlugName ) {
                ConnectionSystem fnConnection( self->getID() );
                fnConnection.connect( sourcePlugName, targetNode->getID(), targetPlugName );
            })
            .def("disconnect", []( AbstractNode* self,
                                const PlugName& sourcePlugName,
                                AbstractNode* targetNode,
                                const PlugName& targetPlugName ) {
                ConnectionSystem fnConnection( self->getID() );
                fnConnection.disconnect( sourcePlugName, targetNode->getID(), targetPlugName );
            })
            .def("setInput", []( AbstractNode* self,
                                 const std::string& name,
                                 const py::object& value ) {
                PlugSystem fnPlug( self->getID() );
                fnPlug.setInput( name, castFromPy( value ) );
            })
            .def("setOutput", []( AbstractNode* self,
                                  const std::string& name,
                                  const py::object& value ) {
                PlugSystem fnPlug( self->getID() );
                fnPlug.setOutput( name, castFromPy( value ) );
            })
            .def("getInput", []( AbstractNode* self,
                                 const PlugName& name )->py::object{
                PlugSystem fnPlug( self->getID() );
                return castToPy( fnPlug.getInput( name ) );
            })
            .def("getOutput", []( AbstractNode* self,
                                 const PlugName& name ){
                PlugSystem fnPlug( self->getID() );
                return castToPy( fnPlug.getOutput( name ) );
            })
            .def("hasInput", []( AbstractNode* self,
                                 const PlugName& name )->bool{
                PlugSystem fnPlug( self->getID() );
                return fnPlug.hasInput( name );
            })
            .def("hasOutput", []( AbstractNode* self,
                                  const PlugName& name )->bool{
                PlugSystem fnPlug( self->getID() );
                return fnPlug.hasOutput( name );
            })
            .def("getInputs", []( AbstractNode* self )->std::vector< PlugName >{
                std::vector< PlugName > inputs =
                        BMO_PlugManager->getOwnerPlugNames( self->getID(), PlugDirectionPolicy::Input );
                return inputs;
            })
            .def("getOutputs", []( AbstractNode* self )->std::vector< PlugName >{
                std::vector< PlugName > outputs =
                        BMO_PlugManager->getOwnerPlugNames( self->getID(), PlugDirectionPolicy::Output );
                return outputs;
            })
            .def("__repr__", []( const AbstractNode& n ){
                std::stringstream ss;
                ss << "<AbstractNode(";
                ss << "addr=" << (void*)&n;
                ss << ", id=" << n.getID();
                ss << ")>";
                return ss.str();
            });
}