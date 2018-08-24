#include "PyNode.hh"

#include <BCore/API.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/Plug.hh>
#include <BCore/managers/DataBlockManager.hh>

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

void py_genNodeAbstractNode( py::module& m ) {

    py::class_<AbstractNode, PyNode>(m, "AbstractNode")
            .def(py::init<>())
            .def("getID", &AbstractNode::getID)
            .def("getType", &AbstractNode::getType)
            .def("getName", &AbstractNode::getName)
            .def("setName", &AbstractNode::setName)
            .def("isValid", &AbstractNode::isValid)
            .def("execute", &AbstractNode::execute)
            .def("setInput", []( AbstractNode* self,
                                 const std::string& name,
                                 const py::object& value ) {
                if ( py::isinstance< py::int_ >( value ) ) {
                    BMO_ERROR << "Setting '" << name << "', value (int): " << value.cast< int >();
                    self->setInput( name, Variant( value.cast< int >() ) );
                } else if ( py::isinstance< py::float_ >( value ) ) {
                    BMO_ERROR << "Setting '" << name << "', value (float): " << value.cast< float >();
                    self->setInput( name, Variant( value.cast< float >() ) );
                } else if ( py::isinstance< py::str >( value ) ) {
                    BMO_ERROR << "Setting '" << name << "', value (string): " << value.cast< std::string >();
                    self->setInput( name, Variant( value.cast< std::string >() ) );
                } else if ( py::isinstance< py::none >( value ) ) {
                    BMO_ERROR << "Setting '" << name << "', value (none)";
                    self->setInput( name, Variant() );
                } else {
                    BMO_ERROR << "Unrecognised '" << name << "', value (\?\?\?)";

//                    py::module cp = py::module::import( "cPickle" );
//                    py::object pickled = cp.attr( "dumps" )( value );
//                    BMO_ERROR << "Pickling '" << name << "', value (string): " << pickled.cast< std::string >();
//                    self->setInput( name, Variant( value.cast< std::string >() ) );
                }

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