#include "Event.hh"

namespace bemo {

NodeCreatedEvent::NodeCreatedEvent( ObjectID id )
    : Event< NodeCreatedEvent >(), m_id( id ) {}
ObjectID NodeCreatedEvent::getNodeID() const { return m_id; }

NodeRemovedEvent::NodeRemovedEvent( ObjectID id )
        : Event< NodeRemovedEvent >(), m_id( id ) {}
ObjectID NodeRemovedEvent::getNodeID() const { return m_id; }

NodeConnectedEvent::NodeConnectedEvent( ObjectID source, ObjectID target )
        : Event< NodeConnectedEvent >(), m_source( source ), m_target( target ) {}
ObjectID NodeConnectedEvent::getSourceNodeID() const { return m_source; }
ObjectID NodeConnectedEvent::getTargetNodeID() const { return m_target; }

NodeDisconnectedEvent::NodeDisconnectedEvent( ObjectID source, ObjectID target )
        : Event< NodeDisconnectedEvent >(), m_source( source ), m_target( target ) {}
ObjectID NodeDisconnectedEvent::getSourceNodeID() const { return m_source; }
ObjectID NodeDisconnectedEvent::getTargetNodeID() const { return m_target; }

}