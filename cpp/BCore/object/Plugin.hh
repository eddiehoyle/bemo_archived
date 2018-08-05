#ifndef BEMO_PLUGIN_HH
#define BEMO_PLUGIN_HH

#include "Object.hh"

namespace bemo {

using PluginID = Handle< u32, 16, 16 >;

class Plugin {
public:
    void addPlug( const std::string& name,
                  PlugDirection direction,
                  PlugType type,
                  bool mandatory,
                  bool strict ) {
    }
private:
    PluginID m_pluginID;
};

}


#endif // BEMO_PLUGIN_HH
