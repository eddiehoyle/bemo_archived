#ifndef BEMO_PLUGINMANAGER_HH
#define BEMO_PLUGINMANAGER_HH

#include <BCore/object/Plugin.hh>
#include <BCore/internal/Table.hh>
#include <BCore/internal/Object.hh>
#include <BCore/managers/ObjectManager.hh>

namespace bemo {

class PluginManager {

public:
    ObjectID create() {
        ObjectID id = BMO_ObjectManager->acquire( ObjectType::Plugin );
        Plugin* plugin = new Plugin();
        plugin->m_id = id;
        m_plugins.push_back( plugin );
        return id;
    }

    Plugin* find( const ObjectID& id ) const {
        auto iter = std::find_if( m_plugins.begin(),
                m_plugins.end(),
                [id]( Plugin* plugin ) {
            return plugin->m_id == id;
        });
        return iter != m_plugins.end() ? *iter : nullptr;
    }
private:
    std::vector< Plugin* > m_plugins;

};

}

#endif // BEMO_PLUGINMANAGER_HH
