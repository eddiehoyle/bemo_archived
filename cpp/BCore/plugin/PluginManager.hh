#ifndef BEMO_PLUGINMANAGER_HH
#define BEMO_PLUGINMANAGER_HH

#include "Plugin.hh"
#include <BCore/object/ObjectManager.hh>
#include <vector>

namespace bemo {

class PluginManager {
public:
    static PluginManager& instance();
public:
    PluginManager(PluginManager const&) = delete;
    void operator=(PluginManager const&) = delete;
public:

    ObjectID create() {
        Plugin* plugin = new Plugin();
        m_plugins.push_back( plugin );
        return plugin->getObjectID();
    }

//    void addWrapper( ObjectID plugin,
//                     const std::string& name,
//                     AbstractCreateFuncWrapper* wrapper ) {
//        m_createFunctors[ plugin ] = std::make_pair( name, wrapper );
//    }
//
//    AbstractCreateFuncWrapper* get( const std::string& name ) const {
//        for ( auto stuff : m_createFunctors ) {
//            if ( stuff.second.first == name ) {
//                return stuff.second.second;
//            }
//        }
//        return nullptr;
//    }

private:
    PluginManager();
    std::vector< Plugin* > m_plugins;
//    std::map< ObjectID, std::pair< std::string, AbstractCreateFuncWrapper* > > m_createFunctors;
};


}

#endif // BEMO_PLUGINMANAGER_HH
