#ifndef BEMO_PLUGINMANAGER_HH
#define BEMO_PLUGINMANAGER_HH

#include <BCore/object/Plugin.hh>
#include "AbstractManager.hh"

namespace bemo {

using PluginID = ObjectID;

class PluginManager {

    using PluginName = std::string;
    using PluginMap = std::map< PluginName, PluginID >;

public:
    virtual ~PluginManager() = default;
    PluginID acquire() {
        return PluginID( 0 );
    }
private:
    PluginMap m_pluginMap;

};

}

#endif // BEMO_PLUGINMANAGER_HH
