#ifndef BEMO_PLUGINMANAGER_HH
#define BEMO_PLUGINMANAGER_HH

#include <BCore/object/Plugin.hh>
#include "AbstractManager.hh"

namespace bemo {

std::function< void() > Func;


class PluginManager : public AbstractManager< Plugin > {

    using PluginName = std::string;
    using PluginID = ObjectID;
    using PluginMap = std::map< PluginName, PluginID >;

public:
    void registerNode( const std::string& name,
                       TypeID typeID,
                       std::function< ObjectID() > creator ) {
    }
    void unregisterNode( const std::string& name ) {
    }
private:
    PluginMap m_pluginMap;

};

}

#endif // BEMO_PLUGINMANAGER_HH
