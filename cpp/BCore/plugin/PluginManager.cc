#include "PluginManager.hh"
#include "PluginSystem.hh"
#include <BCore/node/MultiplyNode.hh>

#include <functional>

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace py = pybind11;

namespace bemo {

PluginManager& PluginManager::instance() {
    static PluginManager mgr;
    return mgr;
}

PluginManager::PluginManager() {

    const std::string modulePath = "/Users/eddiehoyle/Code/cpp/bemo/py/plugins/core.py";

    py::object scope = py::module::import( "__main__" ).attr( "__dict__" );
    py::eval_file( modulePath, scope );
    py::dict globals = scope.cast< py::dict >();
    if ( globals.contains( "bmo_registerPlugin" ) ) {
        py::object init = globals[ "bmo_registerPlugin" ];
        if ( py::hasattr( init, "__call__" ) ) {
            init( PluginManager::instance().create() );
        }
    }

}

}