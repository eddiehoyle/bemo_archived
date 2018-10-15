#ifndef BEMO_DAG_HH
#define BEMO_DAG_HH

#include <old/BCore/internal/Object.hh>
#include "DagVertex.hh"

namespace bemo {

class NodeCreatedEvent;
class NodeRemovedEvent;
class PlugConnectedEvent;
class PlugDisconnectedEvent;

class DagManager {

    using IndexMap = std::map< ObjectID, std::size_t >;
    using Vertices = std::vector< Vertex* >;

public:
    DagManager();
    ~DagManager();

    bool canConnect( ObjectID sourcePlugID, ObjectID targetPlugID ) const;

private:

    /// Signals
    void nodeCreated( NodeCreatedEvent* event );
    void nodeRemoved( NodeRemovedEvent* event );
    void nodeConnected( PlugConnectedEvent* event );
    void nodeDisconnected( PlugDisconnectedEvent* event );

private:

    /// Private functions
    void addVertex( ObjectID nodeID );
    void removeVertex( ObjectID nodeID );
    void addEdge( ObjectID sourcePlugID, ObjectID targetPlugID );
    void removeEdge( ObjectID sourcePlugID, ObjectID targetPlugID );
    bool isDependency( Vertex* sourceVertex,
                       Vertex* targetVertex,
                       std::vector< bool >& visited ) const;

private:
    IndexMap m_indexMap;
    Vertices m_vertices;
};

}

#endif // BEMO_DAG_HH
