#include "Node.hh"
#include "BCore/object/ObjectManager.hh"

namespace bemo {

BDagNode::BDagNode() : m_objectID( ObjectID::invalid() ),
                       m_name( "invalid" ),
                       m_type( "null" ) {}

BDagNode::~BDagNode() { ObjectManager::instance().release( getObjectID() ); }

bool BDagNode::isValid() const {
    return ObjectManager::instance().exists( getObjectID() );
}

}