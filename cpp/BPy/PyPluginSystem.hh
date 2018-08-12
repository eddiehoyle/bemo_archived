#ifndef BEMO_PYPLUGINMANAGER_HH
#define BEMO_PYPLUGINMANAGER_HH

#include "PyNodeManager.hh"

#include <BCore/object/Plugin.hh>
#include <BCore/system/PluginSystem.hh>

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>


namespace py = pybind11;

namespace bemo {

class PyPluginSystem : public PluginSystem {
public:
   explicit PyPluginSystem( PluginID id ) : PluginSystem( id ) {}
   void registerNode( const std::string& type,
                      FnCreate fnCreate,
                      FnLayout fnLayout ) {
       BMO_PyNodeManager->addBlueprint( type, fnCreate, fnLayout );
   }

};

}

#endif // BEMO_PYPLUGINMANAGER_HH
