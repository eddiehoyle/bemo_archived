#ifndef BEMO_PLUGIN_HH
#define BEMO_PLUGIN_HH

#include "Object.hh"

namespace bemo {

using PluginID = Handle< u32, 16, 16 >;
using PluginHeaderID = Handle< u32, 16, 16 >;

class Plugin {

    friend class PluginManager;

public:
    Plugin() : m_pluginID( PluginID::INVALID_HANDLE ),
               m_pluginHeaderID( PluginID::INVALID_HANDLE ),
               m_loaded( false ) {}
    void load() { m_loaded = true; }
    void unload() { m_loaded = false; }
    bool isLoaded() const { return m_loaded; }
private:
    PluginID m_pluginID;
    PluginHeaderID m_pluginHeaderID;
    bool m_loaded;
};

}


#endif // BEMO_PLUGIN_HH
