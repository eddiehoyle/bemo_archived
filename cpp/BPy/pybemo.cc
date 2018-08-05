
#include "pybemo.hh"
#include "PyAbstractNode.hh"
#include "PyNodeManager.hh"
#include "PyNodeRegistry.hh"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include <BCore/API.hh>
#include <BCore/util/Log.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/system/NodeRegistrySystem.hh>

#include <memory>
#include <sstream>
#include <string>
#include <list>

namespace py = pybind11;

using namespace bemo;

void py_initialize() {
    BMO_PyNodeManager = new PyNodeManager();
    BMO_PyNodeRegistry = new PyNodeRegistry();
}


PYBIND11_MODULE(pybemo, m) {

    m.def("init", [](){
        initialize();
        py_initialize();
    });
    m.def("add", []( const std::string& type, CreatorFunc& creFunc, InitFunc& initFunc ){
        BMO_PyNodeRegistry->add( type, creFunc, initFunc );
    });
    m.def("create", []( const std::string& type ){
        return BMO_PyNodeManager->create( type );
    });

    py::class_<NodeRegistrySystem>(m, "NodeRegistrySystem")
            .def(py::init<NodeID>())
            .def("addHeader", &NodeRegistrySystem::addHeader)
            .def("addPlug", &NodeRegistrySystem::addPlug);

    py::class_<NodeID>(m, "NodeID")
            .def(py::init<>());

    py::class_<AbstractNode, PyAbstractNode>(m, "AbstractNode")
            .def(py::init<>())
            .def("nodeID", &AbstractNode::nodeID)
            .def("typeID", &AbstractNode::typeID)
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

