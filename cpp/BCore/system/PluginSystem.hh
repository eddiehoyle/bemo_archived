#ifndef BEMO_PLUGINSYSTEM_HH
#define BEMO_PLUGINSYSTEM_HH

#include <BCore/object/Plugin.hh>

namespace bemo {

using ObjectID = Handle< u32, 16, 16 >;

template< typename C, typename L >
class PluginSystem {
public:
    explicit PluginSystem( const PluginID& id ) : m_id( id ) {}
    void setHeader( const std::string& name,
                    const std::string& description,
                    const std::string& icon ) {}
    void registerNode( const std::string& name,
                       C& fnCreate,
                       L& fnLayout ) {}
private:
    PluginID m_id;

};

}

#endif // BEMO_PLUGINSYSTEM_HH
