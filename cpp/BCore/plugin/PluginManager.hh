#ifndef BEMO_PLUGINMANAGER_HH
#define BEMO_PLUGINMANAGER_HH

#include "Plugin.hh"
#include <vector>

namespace bemo {

class PluginManager {
public:
    static PluginManager& instance();
public:
    PluginManager(PluginManager const&) = delete;
    void operator=(PluginManager const&) = delete;
private:
    PluginManager() {}
    std::vector< std::shared_ptr< Plugin > > m_plugins;
};


}

#endif // BEMO_PLUGINMANAGER_HH
