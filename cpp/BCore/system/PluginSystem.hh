#ifndef BEMO_PLUGINSYSTEM_HH
#define BEMO_PLUGINSYSTEM_HH

#include <BCore/Bemo.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/object/Plugin.hh>

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
        BMO->getNodeManager()->addBlueprint( name,
                                       new CreateFuncWrapper< C >( fnCreate ),
                                       new LayoutFuncWrapper< L >( fnLayout ) );
    }
private:
    ObjectID m_id;
};

}

#endif // BEMO_PLUGINSYSTEM_HH
