#include "Event.hh"

namespace bemo {

int increment() {
    static int s_count;
    return s_count++;
}

NodeCreatedEvent::NodeCreatedEvent( ObjectID id )
    : Event< NodeCreatedEvent >(), m_id( id ) {
    BMO_ERROR << "created NodeCreatedEvent() : EVENT_TYPE_ID=" << EVENT_TYPE_ID;
}
ObjectID NodeCreatedEvent::getNodeID() const { return m_id; }

NodeRemovedEvent::NodeRemovedEvent( ObjectID id )
        : Event< NodeRemovedEvent >(), m_id( id ) {
    BMO_ERROR << "created NodeRemovedEvent() : EVENT_TYPE_ID=" << EVENT_TYPE_ID;
}
ObjectID NodeRemovedEvent::getNodeID() const { return m_id; }

NodeConnectedEvent::NodeConnectedEvent( ObjectID source, ObjectID target )
        : Event< NodeConnectedEvent >(), m_source( source ), m_target( target ) {
    BMO_ERROR << "created NodeConnectedEvent() : EVENT_TYPE_ID=" << EVENT_TYPE_ID;
}
ObjectID NodeConnectedEvent::getSourceNodeID() const { return m_source; }
ObjectID NodeConnectedEvent::getTargetNodeID() const { return m_target; }

NodeDisconnectedEvent::NodeDisconnectedEvent( ObjectID source, ObjectID target )
        : Event< NodeDisconnectedEvent >(), m_source( source ), m_target( target ) {
    BMO_ERROR << "created NodeDisconnectedEvent() : EVENT_TYPE_ID=" << EVENT_TYPE_ID;
}
ObjectID NodeDisconnectedEvent::getSourceNodeID() const { return m_source; }
ObjectID NodeDisconnectedEvent::getTargetNodeID() const { return m_target; }

}