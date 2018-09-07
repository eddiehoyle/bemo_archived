#include "DagManager.hh"
#include <BCore/Bemo.hh>
#include <BCore/event/Event.hh>
#include <BCore/event/EventHandler.hh>
#include <BCore/managers/PlugManager.hh>

namespace bemo {

DagManager::DagManager()
        : m_indexMap(),
          m_vertices() {
    BMO_EventHandler->subscribeEvent< DagManager, NodeCreatedEvent >( this,
                                                                      &DagManager::nodeCreated );
    BMO_EventHandler->subscribeEvent< DagManager, NodeRemovedEvent >( this,
                                                                      &DagManager::nodeRemoved );
    BMO_EventHandler->subscribeEvent< DagManager, PlugConnectedEvent >( this,
                                                                        &DagManager::nodeConnected );
    BMO_EventHandler->subscribeEvent< DagManager, PlugDisconnectedEvent >( this,
                                                                           &DagManager::nodeDisconnected );
}

DagManager::~DagManager() {
    for ( Vertex* vertex : m_vertices ) {
        delete vertex;
    }
    BMO_EventHandler->unsubscribeEvent< DagManager, NodeCreatedEvent >( this );
    BMO_EventHandler->unsubscribeEvent< DagManager, NodeRemovedEvent >( this );
    BMO_EventHandler->unsubscribeEvent< DagManager, PlugConnectedEvent >(
            this );
    BMO_EventHandler->unsubscribeEvent< DagManager, PlugDisconnectedEvent >(
            this );
}

bool
DagManager::canConnect( ObjectID sourcePlugID, ObjectID targetPlugID ) const {
    ObjectID sourceNodeID = BMO_PlugManager->getOwner( sourcePlugID );
    ObjectID targetNodeID = BMO_PlugManager->getOwner( targetPlugID );
    std::vector< bool > visited( m_vertices.size(), false );
    return !isDependency( m_vertices[m_indexMap.at( sourceNodeID )],
                          m_vertices[m_indexMap.at( targetNodeID )],
                          visited );
}

void DagManager::nodeCreated( NodeCreatedEvent* event ) {
    BMO_ERROR << "received node created! id=" << event->getNodeID();
    addVertex( event->getNodeID() );
}

void DagManager::nodeRemoved( NodeRemovedEvent* event ) {
    BMO_ERROR << "received node removed! id=" << event->getNodeID();
    removeVertex( event->getNodeID() );
}

void DagManager::nodeConnected( PlugConnectedEvent* event ) {
    BMO_ERROR << "received node connected!"
              << " source=" << event->getSourcePlugID()
              << ", target=" << event->getTargetPlugID();
    addEdge( event->getSourcePlugID(), event->getTargetPlugID() );
}

void DagManager::nodeDisconnected( PlugDisconnectedEvent* event ) {
    BMO_ERROR << "received node disconnected!"
              << " source=" << event->getSourcePlugID()
              << ", target=" << event->getTargetPlugID();
    removeEdge( event->getSourcePlugID(), event->getTargetPlugID() );
}

void DagManager::addVertex( ObjectID nodeID ) {
    if ( m_indexMap.find( nodeID ) == m_indexMap.end() ) {
        m_indexMap[nodeID] = m_vertices.size();
        m_vertices.push_back( new Vertex( nodeID ) );
    }
}

void DagManager::removeVertex( ObjectID nodeID ) {
    for ( Vertex* vertex : m_vertices ) {
        if ( vertex->has( m_vertices[m_indexMap.at( nodeID )] ) ) {
            vertex->remove( m_vertices[m_indexMap.at( nodeID )] );
        }
    }
    delete m_vertices[m_indexMap.at( nodeID )];
    m_vertices.erase( m_vertices.begin() + m_indexMap.at( nodeID ) );
    m_indexMap.erase( nodeID );
}

void DagManager::addEdge( ObjectID sourcePlugID, ObjectID targetPlugID ) {
    if ( canConnect( sourcePlugID, targetPlugID ) ) {
        ObjectID sourceNodeID = BMO_PlugManager->getOwner( sourcePlugID );
        ObjectID targetNodeID = BMO_PlugManager->getOwner( targetPlugID );
        m_vertices[m_indexMap.at( sourceNodeID )]->add(
                m_vertices[m_indexMap.at( targetNodeID )] );
    }
}

void DagManager::removeEdge( ObjectID sourcePlugID, ObjectID targetPlugID ) {
    ObjectID sourceNodeID = BMO_PlugManager->getOwner( sourcePlugID );
    ObjectID targetNodeID = BMO_PlugManager->getOwner( targetPlugID );
    m_vertices[m_indexMap.at( sourceNodeID )]->remove(
            m_vertices[m_indexMap.at( targetNodeID )] );
}

bool DagManager::isDependency( Vertex* sourceVertex,
                               Vertex* targetVertex,
                               std::vector< bool >& visited ) const {

    if ( sourceVertex->value() == targetVertex->value() ) {
        return true;
    }

    std::size_t index = m_indexMap.at( sourceVertex->value() );
    if ( visited[index] ) {
        return false;
    }
    visited[index] = true;

    for ( Vertex* vertex : sourceVertex->get() ) {
        if ( isDependency( vertex, targetVertex, visited ) ) {
            return true;
        }
    }
    return false;
}

}