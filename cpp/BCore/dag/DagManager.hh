#ifndef BEMO_DAG_HH
#define BEMO_DAG_HH

#include <BCore/internal/Object.hh>
#include "DagVertex.hh"

namespace bemo {

class NodeCreatedEvent;
class NodeRemovedEvent;
class NodeConnectedEvent;
class NodeDisconnectedEvent;

class DagManager {
public:
    DagManager();

    ~DagManager();

    bool canConnect( ObjectID u, ObjectID v ) {
        std::vector< bool > visited( m_vertices.size(), false );
//        Vertex* uvert = m_vertices[m_indexMap[u]];
//        Vertex* uvert = m_vertices[0];
//        BMO_ERROR << "u index=" << m_indexMap[u] << ", u value=" << uvert->value();
        BMO_ERROR << m_indexMap[v] << ", " << m_indexMap[u];
        return !isDependency( m_vertices[m_indexMap[v]],
                              m_vertices[m_indexMap[u]],
                              visited );
//        return !isDependency( m_vertices[0],
//                              m_vertices[1],
//                              visited );
    }

private:
    void nodeCreated( NodeCreatedEvent* event );
    void nodeRemoved( NodeRemovedEvent* event );
    void nodeConnected( NodeConnectedEvent* event );
    void nodeDisconnected( NodeDisconnectedEvent* event );

private:

    void addVertex( ObjectID u ) {
        if ( m_indexMap.find( u ) == m_indexMap.end() ) {
            m_indexMap[u] = m_vertices.size();
            BMO_ERROR << "u=" << u << ", index=" << m_indexMap[u];
            m_vertices.push_back( new Vertex( u ) );
        }
    }

    void removeVertex( ObjectID u ) {
        for ( Vertex* vertex : m_vertices ) {
            if ( vertex->has( m_vertices[m_indexMap[u]] ) ) {
                vertex->remove( m_vertices[m_indexMap[u]] );
            }
        }
        delete m_vertices[m_indexMap[u]];
        m_vertices.erase( m_vertices.begin() + m_indexMap[u] );
        m_indexMap.erase( u );
    }

    void addEdge( ObjectID u, ObjectID v ) {
        if ( canConnect( u, v ) ) {
            m_vertices[m_indexMap[u]]->add( m_vertices[m_indexMap[v]] );
        }
    }

    void removeEdge( ObjectID u, ObjectID v ) {
        m_vertices[m_indexMap[u]]->remove( m_vertices[m_indexMap[v]] );
    }

    bool isDependency( Vertex* source, Vertex* target,
                       std::vector< bool >& visited ) {
        BMO_ERROR << source->value() << ", " << target->value();
        if ( source->value() == target->value() ) {
            return true;
        }

        std::size_t index = m_indexMap[source->value()];
        if ( visited[index] ) {
            return false;
        }
        visited[index] = true;

        for ( Vertex* vertex : source->get() ) {
            bool result = isDependency( vertex, target, visited );
            if ( result ) {
                return result;
            }
        }
        return false;
    }

private:
    std::map< ObjectID, std::size_t > m_indexMap;
    std::vector< Vertex* > m_vertices;
};

}

#endif // BEMO_DAG_HH
