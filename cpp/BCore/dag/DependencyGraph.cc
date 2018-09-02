#include "DependencyGraph.hh"
#include <BCore/Bemo.hh>
#include <BCore/event/Event.hh>
#include <BCore/event/EventManager.hh>

namespace bemo {

DependencyGraph::DependencyGraph()
        : m_indexMap(),
          m_vertices() {
    // This is running before BMO has finished construction
//    BMO_ASSERT( BMO->getEventManager() != nullptr );
//    BMO->getEventManager()->subscribe< DependencyGraph, NodeCreatedEvent >( this, &DependencyGraph::nodeCreated );
//    BMO->getEventManager()->subscribe< DependencyGraph, NodeRemovedEvent >( this, &DependencyGraph::nodeRemoved );
//    BMO->getEventManager()->subscribe< DependencyGraph, NodeConnectedEvent >( this, &DependencyGraph::nodeConnected );
//    BMO->getEventManager()->subscribe< DependencyGraph, NodeDisconnectedEvent >( this, &DependencyGraph::nodeDisconnected );
}

DependencyGraph::~DependencyGraph() {
    for ( Vertex* vertex : m_vertices ) {
        delete vertex;
    }
//    BMO->getEventManager()->unsubscribe< DependencyGraph, NodeCreatedEvent >( this );
//    BMO->getEventManager()->unsubscribe< DependencyGraph, NodeRemovedEvent >( this );
//    BMO->getEventManager()->unsubscribe< DependencyGraph, NodeConnectedEvent >( this );
}


void DependencyGraph::nodeCreated( NodeCreatedEvent* event ) {
    BMO_ERROR << "received node created! id=" << event->getNodeID();
}
void DependencyGraph::nodeRemoved( NodeRemovedEvent* event ) {
    BMO_ERROR << "received node removed! id=" << event->getNodeID();
}
void DependencyGraph::nodeConnected( NodeConnectedEvent* event ) {
    BMO_ERROR << "received node connected!"
              << " source=" << event->getSourceNodeID()
              << ", target=" << event->getTargetNodeID();
}
void DependencyGraph::nodeDisconnected( NodeDisconnectedEvent* event ) {
    BMO_ERROR << "received node disconnected!"
              << " source=" << event->getSourceNodeID()
              << ", target=" << event->getTargetNodeID();
}

}