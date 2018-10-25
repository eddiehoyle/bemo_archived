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



}

}