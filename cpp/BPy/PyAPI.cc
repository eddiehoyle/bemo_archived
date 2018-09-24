#include <BCore/Bemo.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/Plugin.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/PluginManager.hh>

#include "PyAbstractNode.hh"

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

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


PyProxyNodePtr cpp_create( const NodeType& type, const NodeName& name ) {

    if ( BMO_NodeManager == nullptr ) {
        throw std::runtime_error( "Bemo not initialised!" );
    }

    AbstractNode* node = BMO_NodeManager->create( type, name );
    return PyProxyNodePtr( new PyProxyNode( node->getID() ) );
}

void cpp_remove( PyProxyNode* node ) {
    BMO_NodeManager->remove( node->getID() );
}

std::size_t cpp_count() {
    return BMO_NodeManager->count();
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

    m.def( "create",
            &cpp_create,
            py::arg("type"), py::arg("name") = "",
            py::return_value_policy::take_ownership );

    m.def("remove", &cpp_remove );
    m.def("count", &cpp_count);
    m.def("ls", &cpp_ls);
}