#include "PyNode.hh"

#include <BCore/API.hh>
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

static py::object castValue( const Variant& var, VariantType strictType, bool strict ) {

    bool result;
    py::object value;

    BMO_ERROR << "strictType=" << (int)strictType << ", strict=" << strict;

    if ( strict ) {
        switch ( strictType ) {
            case VariantType::Int:
                value = py::int_( var.toInt( &result ) );
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

    } else {
        switch ( var.type() ) {
            case VariantType::Int:
                value = py::int_( var.toInt( &result ) );
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
                ObjectID plugID = self->getInput( name );
                Plug* plug = BMO_PlugManager->find( plugID );
                if ( plug && plug->isValid() ) {
                    if ( plug->isStrict() ) {
                        switch ( plug->getType() ) {
                            case VariantType::Int:
                                if ( py::isinstance< py::int_ >( value ) ) {
                                    self->setInput( name, Variant( value.cast< int >() ) );
                                }
                                break;
                            case VariantType::Float:
                                if ( py::isinstance< py::float_ >( value ) ) {
                                    self->setInput( name, Variant( value.cast< float >() ) );
                                }
                                break;
                            case VariantType::Null:
                            default:
                                ;
                        }
                    } else {
                        if ( py::isinstance< py::int_ >( value ) ) {
                            BMO_ERROR << "Setting Input '" << name << "', value (int): " << value.cast< int >();
                            self->setInput( name, Variant( value.cast< int >() ) );
                        } else if ( py::isinstance< py::float_ >( value ) ) {
                            BMO_ERROR << "Setting Input '" << name << "', value (float): " << value.cast< float >();
                            self->setInput( name, Variant( value.cast< float >() ) );
                        } else if ( py::isinstance< py::str >( value ) ) {
                            BMO_ERROR << "Setting Input '" << name << "', value (string): " << value.cast< std::string >();
                            self->setInput( name, Variant( value.cast< std::string >() ) );
                        } else if ( py::isinstance< py::none >( value ) ) {
                            BMO_ERROR << "Setting Input '" << name << "', value (none)";
                            self->setInput( name, Variant() );
                        } else {
                            BMO_ERROR << "Unrecognised Output '" << name << "', value (\?\?\?)";
                        }
                    }
                }

            })
            .def("setOutput", []( AbstractNode* self,
                                  const std::string& name,
                                  const py::object& value ) {

//                ObjectID plugID = self->getOutput( name );
//                Plug* plug = BMO_PlugManager->find( plugID );
//                if ( plug && plug->isValid() ) {
//                    if ( plug->isStrict() ) {
//                        switch ( plug->getType() ) {
//                            case VariantType::Int:
//                                if ( py::isinstance< py::int_ >( value ) ) {
//                                    self->setOutput( name, Variant( value.cast< int >() ) );
//                                }
//                                break;
//                            case VariantType::Float:
//                                if ( py::isinstance< py::float_ >( value ) ) {
//                                    self->setOutput( name, Variant( value.cast< float >() ) );
//                                }
//                                break;
//                            case VariantType::Null:
//                            default:
//                                ;
//                        }
//                    } else {
//                        if ( py::isinstance< py::int_ >( value ) ) {
//                            BMO_ERROR << "Setting Output '" << name << "', value (int): " << value.cast< int >();
//                            self->setOutput( name, Variant( value.cast< int >() ) );
//                        } else if ( py::isinstance< py::float_ >( value ) ) {
//                            BMO_ERROR << "Setting Output '" << name << "', value (float): " << value.cast< float >();
//                            self->setOutput( name, Variant( value.cast< float >() ) );
//                        } else if ( py::isinstance< py::str >( value ) ) {
//                            BMO_ERROR << "Setting Output '" << name << "', value (string): " << value.cast< std::string >();
//                            self->setOutput( name, Variant( value.cast< std::string >() ) );
//                        } else if ( py::isinstance< py::none >( value ) ) {
//                            BMO_ERROR << "Setting Output '" << name << "', value (none)";
//                            self->setOutput( name, Variant() );
//                        } else {
//                            BMO_ERROR << "Unrecognised Output '" << name << "', value (\?\?\?)";
//                        }
//                    }
//                }
            })
            .def("getInput", []( AbstractNode* self,
                                 const PlugName& name )->py::object{

                py::object value;

                ObjectID plugID = self->getInput( name );
                Plug* plug = BMO_PlugManager->find( plugID );
                if ( plug && plug->isValid() ) {
                    value = castValue( plug->getValue(),
                                       plug->getType(),
                                       plug->isStrict() );
                }
                return value;
            })
            .def("getOutput", []( AbstractNode* self,
                                 const PlugName& name ){
                py::object value;

                ObjectID plugID = self->getInput( name );
                Plug* plug = BMO_PlugManager->find( plugID );
                if ( plug && plug->isValid() ) {
                    value = castValue( plug->getValue(),
                                       plug->getType(),
                                       plug->isStrict() );
                }
                return value;
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