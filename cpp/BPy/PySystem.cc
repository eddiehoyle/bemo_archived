#include <BCore/Bemo.hh>
#include <BCore/object/Plug.hh>
#include <BCore/system/NodeSystem.hh>
#include <BCore/system/PluginSystem.hh>
#include <BCore/managers/PluginManager.hh>

#include "PyNode.hh"

#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace py = pybind11;
using namespace bemo;

using FnCreate = std::function< py::object() >;
using FnLayout = std::function< py::object( ObjectID ) >;

namespace bemo {

template<>
AbstractNode* CreateFuncWrapper< FnCreate >::invoke() {
    py::object obj = m_func();
    return py::cast< PyNode* >( obj.release() );
}

template<>
void LayoutFuncWrapper< FnLayout >::invoke( ObjectID id ) {
    m_func( id );
}

}

void py_genSystemPluginSystem( py::module& m );


void py_genSystem( py::module& m ) {

    py_genSystemPluginSystem( m );
}


void py_genSystemPluginSystem( py::module& m ) {

    py::class_<PluginSystem>(m, "PluginSystem")
            .def(py::init<ObjectID>())
            .def( "setHeader", &PluginSystem::setHeader )
            .def( "registerNode", &PluginSystem::registerNode<FnCreate, FnLayout> );

    py::class_<NodeSystem>(m, "NodeSystem")
            .def(py::init<ObjectID>())
            .def( "addHeader", &NodeSystem::setHeader )
            .def( "addPlug",
                  &NodeSystem::addPlug,
                  py::arg( "name" ),
                  py::arg( "direction" ),
                  py::arg( "access" ),
                  py::arg( "cast" ),
                  py::arg( "type" ) = VariantType::Null,
                  py::arg( "isRequired" ) = false );

}