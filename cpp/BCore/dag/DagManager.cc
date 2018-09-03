#include "DagManager.hh"
#include <BCore/Bemo.hh>
#include <BCore/event/Event.hh>
#include <BCore/event/EventHandler.hh>

namespace bemo {

DagManager::DagManager()
        : m_indexMap(),
          m_vertices() {
    BMO_EventHandler->subscribe< DagManager, NodeCreatedEvent >( this, &DagManager::nodeCreated );
    BMO_EventHandler->subscribe< DagManager, NodeRemovedEvent >( this, &DagManager::nodeRemoved );
    BMO_EventHandler->subscribe< DagManager, NodeConnectedEvent >( this, &DagManager::nodeConnected );
    BMO_EventHandler->subscribe< DagManager, NodeDisconnectedEvent >( this, &DagManager::nodeDisconnected );
}

DagManager::~DagManager() {
    for ( Vertex* vertex : m_vertices ) {
        delete vertex;
    }
    BMO_EventHandler->unsubscribe< DagManager, NodeCreatedEvent >( this );
    BMO_EventHandler->unsubscribe< DagManager, NodeRemovedEvent >( this );
    BMO_EventHandler->unsubscribe< DagManager, NodeConnectedEvent >( this );
    BMO_EventHandler->unsubscribe< DagManager, NodeDisconnectedEvent >( this );
}


void DagManager::nodeCreated( NodeCreatedEvent* event ) {
    BMO_ERROR << "received node created! id=" << event->getNodeID();
}
void DagManager::nodeRemoved( NodeRemovedEvent* event ) {
    BMO_ERROR << "received node removed! id=" << event->getNodeID();
}
void DagManager::nodeConnected( NodeConnectedEvent* event ) {
    BMO_ERROR << "received node connected!"
              << " source=" << event->getSourceNodeID()
              << ", target=" << event->getTargetNodeID();
}
void DagManager::nodeDisconnected( NodeDisconnectedEvent* event ) {
    BMO_ERROR << "received node disconnected!"
              << " source=" << event->getSourceNodeID()
              << ", target=" << event->getTargetNodeID();
}

}