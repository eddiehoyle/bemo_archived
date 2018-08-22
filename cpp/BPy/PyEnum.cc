#include <BCore/API.hh>
#include <BCore/object/Plug.hh>

#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace bemo;

// Forward decl
void py_genEnumObjectType( py::module& m );
void py_genEnumPlugDirection( py::module& m );
void py_genEnumVariantType( py::module& m );

void py_genEnum( py::module& m ) {

    py_genEnumObjectType( m );
    py_genEnumPlugDirection( m );
    py_genEnumVariantType( m );
}

void py_genEnumObjectType( py::module& m ) {
    py::enum_<ObjectType>( m, "ObjectType" )
            .value( "Header", ObjectType::Node )
            .value( "Node", ObjectType::Node )
            .value( "Plug", ObjectType::Plug )
            .value( "Plugin", ObjectType::Plugin )
            .export_values();
}

void py_genEnumPlugDirection( py::module& m ) {
    py::enum_<PlugDirection>( m, "PlugDirection" )
            .value( "Input", PlugDirection::Input )
            .value( "Output", PlugDirection::Output )
            .export_values();
}

void py_genEnumVariantType( py::module& m ) {
    py::enum_<VariantType>(m, "VariantType")
            .value("Int", VariantType::Int)
            .value("Float", VariantType::Float)
            .value("String", VariantType::String)
            .export_values();
}