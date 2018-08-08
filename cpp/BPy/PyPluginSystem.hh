#ifndef BEMO_PYPLUGINMANAGER_HH
#define BEMO_PYPLUGINMANAGER_HH

#include "PyNodeManager.hh"

#include <BCore/object/Plugin.hh>

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>


namespace py = pybind11;

namespace bemo {

class PyPluginSystem {
public:
   explicit PyPluginSystem( PluginID pluginID ) : m_id( pluginID ) {}
   void setHeader( const std::string& name,
                   const std::string& description ) {}
   void registerNode( const std::string& type,
                      FnCreate fnCreate,
                      FnLayout fnLayout ) {
       BMO_PyNodeManager->addBlueprint( type, fnCreate, fnLayout );
   }
private:
    PluginID m_id;

};

}

#endif // BEMO_PYPLUGINMANAGER_HH
