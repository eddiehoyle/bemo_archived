#ifndef BEMO_PLUGINMANAGER_HH
#define BEMO_PLUGINMANAGER_HH

#include <BCore/object/Plugin.hh>
#include <BCore/internal/Table.hh>

namespace bemo {

class PluginManager {

public:
    PluginID create() {
        PluginID id = m_table.acquire( new Plugin() );
        Plugin* plugin = m_table[ id ];
        plugin->m_pluginID = id;
        return id;
    }

    Plugin* get( PluginID id ) const {
        return m_table[ id ];
    }

private:
    HandleTable< Plugin, PluginID > m_table;
};

}

#endif // BEMO_PLUGINMANAGER_HH
