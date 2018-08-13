#include <BCore/API.hh>
#include <BCore/object/Plug.hh>

#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace bemo;

// Forward decl
void py_genEnumObjectType( py::module& m );
void py_genEnumPlugDirection( py::module& m );
void py_genEnumPlugType( py::module& m );

void py_genEnum( py::module& m ) {

    py_genEnumObjectType( m );
    py_genEnumPlugDirection( m );
    py_genEnumPlugType( m );
}

void py_genEnumObjectType( py::module& m ) {
    py::enum_< ObjectType >( m, "ObjectType" )
            .value( "Header", ObjectType::Node )
            .value( "Node", ObjectType::Node )
            .value( "Plug", ObjectType::Plug )
            .value( "Plugin", ObjectType::Plugin )
            .export_values();
}

void py_genEnumPlugDirection( py::module& m ) {
    py::enum_< PlugDirection >( m, "PlugDirection" )
            .value( "Input", PlugDirection::Input )
            .value( "Output", PlugDirection::Output )
            .export_values();
}

void py_genEnumPlugType( py::module& m ) {
    py::enum_<PlugType>(m, "PlugType")
            .value("Int", PlugType::Int)
            .value("String", PlugType::String)
            .value("Float", PlugType::Float)
            .value("List", PlugType::List)
            .value("Dict", PlugType::Dict)
            .value("Variant", PlugType::Variant)
            .export_values();
}