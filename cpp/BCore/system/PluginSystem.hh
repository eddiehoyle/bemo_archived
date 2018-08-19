#ifndef BEMO_PLUGINSYSTEM_HH
#define BEMO_PLUGINSYSTEM_HH

#include <BCore/object/Plugin.hh>
#include <BCore/API.hh>
#include <BCore/managers/NodeManager.hh>

namespace bemo {

class PluginSystem {
public:
    explicit PluginSystem( const ObjectID& id ) : m_id( id ) {}
    void setHeader( const std::string& name,
                    const std::string& description,
                    const std::string& icon ) {}

    template< typename C, typename L >
    void registerNode( const std::string& name,
                       C fnCreate,
                       L fnLayout ) {
        BMO_NodeManager->addBlueprint( name,
                                       new CreateFuncWrapper< C >( fnCreate ),
                                       new LayoutFuncWrapper< L >( fnLayout ) );
        BMO_ERROR << "Registered node=" << name;
    }
private:
    ObjectID m_id;
};

}

#endif // BEMO_PLUGINSYSTEM_HH
