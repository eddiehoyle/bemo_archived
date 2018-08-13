#include <BCore/API.hh>
#include <BCore/object/Plug.hh>
#include <BPy/system/PyPluginSystem.hh>
#include <BCore/system/NodeSystem.hh>

#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace bemo;

void py_genSystemPluginSystem( py::module& m );

void py_genSystem( py::module& m ) {

    py_genSystemPluginSystem( m );
}

void py_genSystemPluginSystem( py::module& m ) {

    py::class_<PyPluginSystem>(m, "PluginSystem")
            .def(py::init<PluginID>())
            .def( "setHeader", &PyPluginSystem::setHeader )
            .def( "registerNode", &PyPluginSystem::registerNode );

    py::class_<NodeSystem>(m, "NodeSystem")
            .def(py::init<NodeID>())
            .def( "addHeader", &NodeSystem::setHeader )
            .def( "addPlug",
                  &NodeSystem::addPlug,
                  py::arg( "name" ),
                  py::arg( "direction" ),
                  py::arg( "type" ) = PlugType::Variant,
                  py::arg( "isRequired" ) = false,
                  py::arg( "isStrict" ) = false );

}