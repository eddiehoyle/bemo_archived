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
    template< typename T >
    void registerNode( const std::string& name,
                       int nodeTypeID,
                       std::function< T() > creator,
                       std::function< T() > header,
                       std::function< T() > layout ) {
        T node = creator();
        BMO_ERROR << "got node=" << node.objectID();
    }
    void unregisterNode( const std::string& name ) {
    }
private:
    PluginMap m_pluginMap;

};

}

#endif // BEMO_PLUGINMANAGER_HH
