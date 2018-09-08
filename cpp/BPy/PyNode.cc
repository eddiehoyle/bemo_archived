#include "PyNode.hh"

#include <BCore/Bemo.hh>
#include <BCore/object/Plug.hh>
#include <BCore/managers/PlugManager.hh>

#include <pybind11/pybind11.h>

#include <sstream>
#include <stdexcept>

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

    py::class_<AbstractNode, PyNode>(m, "AbstractNode")
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
                self->connect( sourcePlugName, targetNode->getID(), targetPlugName );
            })
            .def("disconnect", &AbstractNode::disconnect)
            .def("setInput", []( AbstractNode* self,
                                 const std::string& name,
                                 const py::object& value ) {
                self->setInput( name, castFromPy( value ) );
            })
            .def("setOutput", []( AbstractNode* self,
                                  const std::string& name,
                                  const py::object& value ) {
                self->setOutput( name, castFromPy( value ) );
            })
            .def("getInput", []( AbstractNode* self,
                                 const PlugName& name )->py::object{
                return castToPy( self->getInput( name ) );
            })
            .def("getOutput", []( AbstractNode* self,
                                 const PlugName& name ){
                return castToPy( self->getOutput( name ) );
            })
            .def("hasInput", &AbstractNode::hasInput)
            .def("hasOutput", &AbstractNode::hasOutput)
            .def("getInputs", &AbstractNode::getInputs)
            .def("getOutputs", &AbstractNode::getOutputs)
            .def("__repr__", []( const AbstractNode& n ){
                std::stringstream ss;
                ss << "<AbstractNode(";
                ss << "addr=" << (void*)&n;
                ss << ", id=" << n.getID();
                ss << ")>";
                return ss.str();
            });
}