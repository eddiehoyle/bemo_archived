#ifndef BEMO_PLUGINMANAGER_HH
#define BEMO_PLUGINMANAGER_HH

#include "Plugin.hh"
#include <BCore/object/ObjectManager.hh>
#include <vector>

namespace bemo {

class AbstractCreateFuncWrapper {
public:
    virtual void* get() = 0;
//    virtual std::function< Object*() > get() = 0;
};

class PluginManager {
public:
    static PluginManager& instance();
public:
    PluginManager(PluginManager const&) = delete;
    void operator=(PluginManager const&) = delete;
public:

    ObjectID create() {
        ObjectID id = ObjectManager::instance().acquire();
        m_plugins.push_back( new Plugin( id ) );
        return id;
    }

    void addWrapper( ObjectID plugin,
                     const std::string& name,
                     AbstractCreateFuncWrapper* wrapper ) {
        m_createFunctors[ plugin ] = std::make_pair( name, wrapper );
    }

    AbstractCreateFuncWrapper* get( const std::string& name ) const {
        for ( auto stuff : m_createFunctors ) {
            if ( stuff.second.first == name ) {
                return stuff.second.second;
            }
        }
        return nullptr;
    }

private:
    PluginManager();
    std::vector< Plugin* > m_plugins;
    std::map< ObjectID, std::pair< std::string, AbstractCreateFuncWrapper* > > m_createFunctors;
};


}

#endif // BEMO_PLUGINMANAGER_HH
