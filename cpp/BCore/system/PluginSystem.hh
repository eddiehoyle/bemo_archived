#ifndef BEMO_PLUGINSYSTEM_HH
#define BEMO_PLUGINSYSTEM_HH

#include <BCore/object/Plugin.hh>

namespace bemo {

using ObjectID = Handle< ObjectType::Invalid, u32, 16, 16 >;

template< typename C, typename L >
class PluginSystem {
public:
    explicit PluginSystem( const ObjectID& id ) : m_id( id ) {}
    void setHeader( const std::string& name,
                    const std::string& description,
                    const std::string& icon ) {}
    void registerNode( const std::string& name,
                       C& fnCreate,
                       L& fnLayout ) {}
private:
    ObjectID m_id;

};

}

#endif // BEMO_PLUGINSYSTEM_HH
