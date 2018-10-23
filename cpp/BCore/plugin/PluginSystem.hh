#ifndef BEMO_PLUGINSYSTEM_HH
#define BEMO_PLUGINSYSTEM_HH

#include <BCore/object/ObjectID.hh>
#include <BCore/node/Node.hh>
#include <BCore/node/NodeRegistry.hh>

#include <memory>
#include <BCore/Assert.hh>
#include <BCore/node/NodeManager.hh>
#include "PluginManager.hh"

namespace bemo {


class PluginSystem {
public:
    explicit PluginSystem( const ObjectID& id ) : m_id( id ) {}
    bool isValid() const { return ObjectManager::instance().exists(m_id); }

    void setHeader( const std::string& name,
                    const std::string& description,
                    const std::string& icon ) {}

    void registerNode( const std::string& type, FnCreate fnCreate, FnLayout fnLayout ) {
        NodeRegistry::instance().add( type, fnCreate, fnLayout );
    }

private:
    ObjectID m_id;

};


}

#endif // BEMO_PLUGINSYSTEM_HH
