#include "Node.hh"
#include "ObjectManager.hh"

namespace bemo {

BDagNode::BDagNode() : m_objectID( ObjectID::invalid() ),
                       m_objectType( ObjectType::kNull ),
                       m_name( "null" ),
                       m_type( "null" ) {}

BDagNode::~BDagNode() { ObjectManager::instance().release( getObjectID() ); }

bool BDagNode::isValid() const {
    return ObjectManager::instance().exists( getObjectID() );
}

}