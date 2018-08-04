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
        return 0;
    }
    void unregisterNode( const std::string& type ) {
    }
};

}

#endif // BEMO_PYPLUGINMANAGER_HH
