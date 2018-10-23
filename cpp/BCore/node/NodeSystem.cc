#include <utility>

#include "NodeSystem.hh"

namespace bemo {

NodeSystem::NodeSystem( ObjectID id )
    : m_id( id ) {
}

bool NodeSystem::isValid() const {
    ObjectManager::instance().exists( m_id );
}

void NodeSystem::setHeader( const std::string& name,
                            const std::string& description,
                            const std::string& icon ) {

}

void NodeSystem::setBlueprint( FnCreate fnCreate, FnLayout fnLayout )  {
    BDagNode* node = NodeManager::instance().find( m_id );
    BMO_ASSERT(node);
    NodeRegistry::instance().add( node->getType(),
            std::move( fnCreate ),
            std::move( fnLayout ) );
}

void
NodeSystem::addPlug( const std::string& name, PlugDirectionPolicy direction,
                     PlugAccessPolicy access, PlugCastPolicy cast,
                     VariantType type, bool isRequired ) {

}

}