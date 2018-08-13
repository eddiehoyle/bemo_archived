#include "PyAPI.hh"
#include "PyNodeManager.hh"

#include <BCore/API.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/Plugin.hh>

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace py = pybind11;
using namespace bemo;

//bemo::PyNodeManager* BMO_PyNodeManager = nullptr;

void py_initialize() {

//    bemo::BMO_PyNodeManager = new PyNodeManager();

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

void py_genAPI( py::module& m ) {

    m.def("init", [](){
        initialize();
        py_initialize();
    });

    m.def("create", []( const std::string& type ){
//        return bemo::BMO_PyNodeManager->create( type );
    });
}