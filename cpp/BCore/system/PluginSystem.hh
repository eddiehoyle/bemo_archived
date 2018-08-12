#ifndef BEMO_PLUGINSYSTEM_HH
#define BEMO_PLUGINSYSTEM_HH

#include <BCore/object/Plugin.hh>

namespace bemo {

class PluginSystem {
public:
    explicit PluginSystem( const PluginID& id ) : m_id( id ) {}
    void setHeader( const std::string& name,
                    const std::string& description,
                    const std::string& icon ) {}
protected:
    PluginID m_id;

};

}

#endif // BEMO_PLUGINSYSTEM_HH
