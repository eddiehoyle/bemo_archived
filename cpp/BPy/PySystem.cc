
#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include <BCore/Assert.hh>
#include <BCore/object/Node.hh>
#include <BCore/object/ObjectID.hh>
#include <BCore/object/ObjectManager.hh>
#include <BCore/plugin/PluginSystem.hh>

#include "PyNode.hh"

using namespace bemo;
namespace py = pybind11;

void py_coreGenPluginSystem( py::module& m );

void py_genSystem( py::module& m ) {
    py_coreGenPluginSystem( m );
}

//typedef std::function<BPyOpenNode*()> PyFnCreate;
//typedef std::function<py::object()> PyFnCreate;
//typedef std::function<void(ObjectID)> PyFnLayout;

//typedef std::function<void(ObjectID)> PyFnLayout;
//typedef std::function<py::object()> PyFnCreate;

void py_coreGenPluginSystem( py::module& m ) {

    py::class_< PluginSystem, std::shared_ptr< PluginSystem > >( m, "PluginSystem" )
            .def( py::init< ObjectID >() )
            .def( "setHeader", &PluginSystem::setHeader )
            .def( "registerNode", &PluginSystem::registerNode<BPyOpenNode*> );
//            .def( "create", []( PluginSystem* self, const std::string& name ) {
//                return std::shared_ptr< BDagNode >( self->create< BDagNode* >( name ) );
//            } );
//            .def( "create", &PluginSystem::create< BDagNode* > );

}

