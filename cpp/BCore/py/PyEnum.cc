#include <old/BCore/Bemo.hh>
#include <old/BCore/object/Plug.hh>

#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace bemo;

// Forward decl
void py_genEnumObjectType( py::module& m );
void py_genEnumPlugDirection( py::module& m );
void py_genEnumVariantType( py::module& m );

void py_genEnum( py::module& m ) {

//    py::enum_<ObjectType>( m, "NodeType" )
//            .value( "Header", ObjectType::Node )
//            .value( "Node", ObjectType::Node )
//            .value( "Plug", ObjectType::Plug )
//            .value( "Plugin", ObjectType::Plugin )
//            .export_values();

    py::enum_<PlugDirectionPolicy>( m, "PlugDirectionPolicy" )
            .value( "Input", PlugDirectionPolicy::Input )
            .value( "Output", PlugDirectionPolicy::Output )
            .export_values();

    py::enum_<PlugAccessPolicy>( m, "PlugAccessPolicy" )
            .value( "Single", PlugAccessPolicy::Single )
            .value( "Multiple", PlugAccessPolicy::Multiple )
            .export_values();

    py::enum_<PlugCastPolicy>( m, "PlugCastPolicy" )
            .value( "Strict", PlugCastPolicy::Strict )
            .value( "Similar", PlugCastPolicy::Similar )
            .value( "Anything", PlugCastPolicy::Anything )
            .export_values();

    py::enum_<VariantType>(m, "VariantType")
            .value("Long", VariantType::Long)
            .value("Float", VariantType::Float)
            .value("String", VariantType::String)
            .export_values();

}
