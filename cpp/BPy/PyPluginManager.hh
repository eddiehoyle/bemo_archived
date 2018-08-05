#ifndef BEMO_PYPLUGINMANAGER_HH
#define BEMO_PYPLUGINMANAGER_HH

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include "PyNodeRegistry.hh"
#include <BCore/managers/PluginManager.hh>

namespace py = pybind11;

namespace bemo {

class PyPluginManager : public PluginManager {
public:
    int registerNode( const std::string& type, CreatorFunc func ) {
        PluginID id = acquire();
        Plugin plugin = Plugin();
        plugin.m_
    }
    void unregisterNode( const std::string& type ) {
    }
};

}

#endif // BEMO_PYPLUGINMANAGER_HH
