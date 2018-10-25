
#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include <BCore/Assert.hh>
#include <BCore/node/Node.hh>
#include <BCore/object/ObjectID.hh>
#include <BCore/object/ObjectManager.hh>
#include <BCore/plugin/PluginSystem.hh>
#include <BCore/node/NodeSystem.hh>

#include "PyNode.hh"

using namespace bemo;
namespace py = pybind11;

void py_coreGenPluginSystem( py::module& m );
void py_coreGenNodeSystem( py::module& m );

void py_genSystem( py::module& m ) {
    py_coreGenPluginSystem( m );
    py_coreGenNodeSystem( m );
}

void py_coreGenPluginSystem( py::module& m ) {

    py::class_< PluginSystem, std::shared_ptr< PluginSystem > >( m, "PluginSystem" )
            .def( py::init< ObjectID >() )
            .def( "setHeader", &PluginSystem::setHeader )
            .def( "registerNode", &PluginSystem::registerNode );
}

void py_coreGenNodeSystem( py::module& m ) {

    py::class_< NodeSystem, std::shared_ptr< NodeSystem > >( m, "NodeSystem" )
            .def( py::init< ObjectID >() )
            .def( "setHeader", &NodeSystem::setHeader )
            .def( "setBlueprint", &NodeSystem::setBlueprint )
            .def( "addPlug",
                  &NodeSystem::addPlug,
                  py::arg( "name" ),
                  py::arg( "direction" ),
                  py::arg( "access" ),
                  py::arg( "cast" ),
                  py::arg( "type" ),
                  py::arg( "isRequired" ) = py::bool_( false ) );
}

