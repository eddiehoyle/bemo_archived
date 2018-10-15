#include "Event.hh"

namespace bemo {

int increment() {
    static int s_count;
    return s_count++;
}

NodeCreatedEvent::NodeCreatedEvent( ObjectID nodeID )
    : Event< NodeCreatedEvent >(), m_nodeID( nodeID ) {
}
ObjectID NodeCreatedEvent::getNodeID() const { return m_nodeID; }

NodeRemovedEvent::NodeRemovedEvent( ObjectID nodeID )
        : Event< NodeRemovedEvent >(), m_nodeID( nodeID ) {
}
ObjectID NodeRemovedEvent::getNodeID() const { return m_nodeID; }

PlugConnectedEvent::PlugConnectedEvent( ObjectID sourcePlugID, ObjectID targetPlugID )
        : Event< PlugConnectedEvent >(), m_sourcePlugID( sourcePlugID ), m_targetPlugID( targetPlugID ) {
}
ObjectID PlugConnectedEvent::getSourcePlugID() const { return m_sourcePlugID; }
ObjectID PlugConnectedEvent::getTargetPlugID() const { return m_targetPlugID; }

PlugDisconnectedEvent::PlugDisconnectedEvent( ObjectID sourcePlugID, ObjectID targetPlugID )
        : Event< PlugDisconnectedEvent >(), m_sourcePlugID( sourcePlugID ), m_targetPlugID( targetPlugID ) {
}
ObjectID PlugDisconnectedEvent::getSourcePlugID() const { return m_sourcePlugID; }
ObjectID PlugDisconnectedEvent::getTargetPlugID() const { return m_targetPlugID; }

}