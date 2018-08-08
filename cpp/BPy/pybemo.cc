
#include "pybemo.hh"
#include "PyNode.hh"
#include "PyNodeManager.hh"
#include "PyPluginSystem.hh"

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include <BCore/API.hh>
#include <BCore/util/Log.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/system/NodeSystem.hh>
#include <BCore/object/Plugin.hh>

#include <memory>
#include <sstream>
#include <string>
#include <list>

namespace py = pybind11;

using namespace bemo;

void py_initialize() {
    BMO_PyNodeManager = new PyNodeManager();

    const std::string modulePath = "/Users/eddiehoyle/Code/cpp/bemo/py/plugin/node.py";

    py::object scope = py::module::import( "__main__" ).attr( "__dict__" );
    py::eval_file( modulePath, scope );
    py::dict globals = scope.cast< py::dict >();
    if ( globals.contains ( "bmo_registerPlugin" ) ) {
        py::object init = globals[ "bmo_registerPlugin" ];
        if ( py::hasattr( init, "__call__" ) ) {
            init( PluginID( 0 ) );
        }
    }
}


PYBIND11_MODULE(pybemo, m) {

    m.def("init", [](){
        initialize();
        py_initialize();
    });
    m.def("add", []( const std::string& type,
                     FnCreate& fnCreate,
                     FnLayout& fnLayout ){
        BMO_PyNodeManager->addBlueprint( type, fnCreate, fnLayout );
    });
    m.def("create", []( const std::string& type ){
        return BMO_PyNodeManager->create( type );
    });

    py::enum_<ObjectType>(m, "ObjectType")
            .value("Header", ObjectType::Node)
            .value("Node", ObjectType::Node)
            .value("Plug", ObjectType::Plug)
            .value("Plugin", ObjectType::Plugin)
            .export_values();

    py::enum_<PlugDirection>(m, "PlugDirection")
            .value("Input", PlugDirection::Input)
            .value("Output", PlugDirection::Output)
            .export_values();

    py::enum_<PlugType>(m, "PlugType")
            .value("Int", PlugType::Int)
            .value("String", PlugType::String)
            .value("Float", PlugType::Float)
            .value("List", PlugType::List)
            .value("Dict", PlugType::Dict)
            .value("Variant", PlugType::Variant)
            .export_values();

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

    py::class_<NodeID>(m, "NodeID")
            .def(py::init<NodeID::NumericType>());

    py::class_<PluginID>(m, "PluginID")
            .def(py::init<PluginID::NumericType>());

    py::class_<AbstractNode, PyNode>(m, "AbstractNode")
            .def(py::init<>())
            .def_static("objectTypeID", []()->ObjectType{ return AbstractNode::OBJECT_TYPE_ID; } )
            .def("nodeID", &AbstractNode::nodeID)
            .def("typeID", &AbstractNode::typeID)
            .def("isValid", &AbstractNode::isValid)
            .def("execute", &AbstractNode::execute)
            .def("__repr__", []( const AbstractNode& n ){
                std::stringstream ss;
                ss << "<AbstractNode(";
                ss << "addr=" << (void*)&n;
                ss << ", id=" << n.nodeID();
                ss << ", type=" << n.typeID();
                ss << ")>";
                return ss.str();
            });
}

