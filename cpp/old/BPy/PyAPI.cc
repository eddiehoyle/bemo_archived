#include <old/BCore/Bemo.hh>
#include <old/BCore/object/Plug.hh>
#include <old/BCore/object/Plugin.hh>
#include <old/BCore/managers/NodeManager.hh>
#include <old/BCore/managers/PluginManager.hh>

#include "PyNode.hh"
#include "PyGraph.hh"

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include <sstream>

namespace py = pybind11;
using namespace bemo;

void py_initialize() {

    const std::string modulePath = "/Users/eddiehoyle/Code/cpp/bemo/py/plugins/core.py";

    py::object scope = py::module::import( "__main__" ).attr( "__dict__" );
    py::eval_file( modulePath, scope );
    py::dict globals = scope.cast< py::dict >();
    if ( globals.contains ( "bmo_registerPlugin" ) ) {
        py::object init = globals[ "bmo_registerPlugin" ];
        if ( py::hasattr( init, "__call__" ) ) {
            init( BMO_PluginManager->create() );
        }
    }
}

PyProxyGraphPtr cpp_createGraph( const GraphType& type, const GraphName& name ) {

    return nullptr;
}


PyProxyNodePtr cpp_create( const NodeType& type, const NodeName& name ) {

    if ( BMO_NodeManager == nullptr ) {
        throw std::runtime_error( "Bemo not initialised!" );
    }

    AbstractNode* node = BMO_NodeManager->create( type, name );
    if ( node == nullptr ) {
        std::stringstream ss;
        ss << "Node type '";
        ss << type;
        ss << "' not a valid type.\n";
        throw py::type_error( ss.str() );
    }

    py::object obj = py::cast( static_cast< PyNode* >( node ) );

    // TODO: Fix this
    while( obj.ref_count() > 1 ) {
        obj.dec_ref();
        break;
    }
    return PyProxyNodePtr( new PyProxyNode( node->getID() ) );
}

void cpp_remove( AbstractProxyObject* node ) {
    BMO_NodeManager->remove( node->getID() );
}

bool cpp_exists( AbstractProxyObject* node ) {
    return BMO_NodeManager->exists( node->getID() );
}

std::vector< PyProxyNodePtr > cpp_ls() {
    std::vector< PyProxyNodePtr > proxyNodes;
    for( auto node: BMO_NodeManager->getNodes() ) {
        proxyNodes.emplace_back( PyProxyNodePtr( new PyProxyNode( node->getID() ) ) );
    }
    return proxyNodes;
}

void py_genAPI( py::module& m ) {

    m.def("initialise", [](){
        initialize();
        py_initialize();
    });

    m.def("terminate", &terminate);

    py::class_<ObjectID>(m, "ObjectID")
            .def(py::init<>())
            .def_static("invalid", &ObjectID::invalid);

    m.def( "create_graph",
            &cpp_createGraph,
            py::arg("type"), py::arg("name") = "",
            py::return_value_policy::take_ownership );

    m.def( "create",
            &cpp_create,
            py::arg("type"), py::arg("name") = "",
            py::return_value_policy::take_ownership );

    m.def("remove", &cpp_remove );
    m.def("ls", &cpp_ls);
    m.def("exists", &cpp_exists);
}