#ifndef BEMO_DAG_HH
#define BEMO_DAG_HH

#include <BCore/internal/Object.hh>

namespace bemo {

class Vertex {
    friend class DependencyGraph;
public:
    explicit Vertex( ObjectID value )
        : m_id( 0 ),
          m_value( value ),
          m_dependencies() {}
    std::size_t id() const { return m_id; }
    ObjectID value() const { return m_value; }
    void add( ObjectID value ) {}
    void remove( ObjectID value ) {}
    std::size_t count() const { return m_dependencies.size(); }
    const std::set< std::size_t >& getDependencies() const { return m_dependencies; }
private:
    std::size_t m_id;
    ObjectID m_value;
    std::set< std::size_t > m_dependencies;
};

class DependencyGraph {
public:
    DependencyGraph() : m_vertices() {}
    ~DependencyGraph() {
        for ( std::size_t index = 0; index < m_vertices.size(); ++index ) {
            Vertex* vertex = m_vertices[ index ];
            if ( vertex != nullptr ) {
                delete vertex;
            }
            m_vertices[ index ] = nullptr;
        }
    }
    void addEdge( ObjectID u, ObjectID v ) {}
    bool canConnect( ObjectID u, ObjectID v ) {
        if ( u == v ) {
            return false;
        }
        const std::vector< bool > visited( m_vertices.size(), false );
        for ( Vertex* vertex : m_vertices ) {
            isDependency( vertex->id(), u, visited );
        }
        return false;
    }
private:
    bool isDependency( std::size_t index,
                       ObjectID target,
                       const std::vector< bool >& visited ) {
        if ( m_vertices[ index ]->value() == target ) {
            return true;
        }
        for ( std::size_t depIndex : m_vertices[ index ]->getDependencies() ) {
            return isDependency( index, target, visited );
        }
        return false;
    }
private:
    std::vector< Vertex* > m_vertices;
};

//struct Vertex;
//struct Edge;
//
//struct Vertex {
//    Edge* input;
//    Edge* output;
//    ObjectID m_id;
//};
//
//struct Edge {
//    Vertex* input;
//    Vertex* output;
//};
//
//struct Dag {
//
//public:
//    void connect( const ObjectID& source, const ObjectID& target ) {
//        auto sourceVertexIter = std::find_if( m_vertices.begin(),
//                                              m_vertices.end(),
//                                              [&]( Vertex* vertex ) {
//                                                  return vertex->m_id == source;
//                                              });
//        auto targetVertexIter = std::find_if( m_vertices.begin(),
//                                              m_vertices.end(),
//                                              [&]( Vertex* vertex ) {
//                                                  return vertex->m_id == target;
//                                              });
//    }
//
//    ObjectID get_vertices() const {
//        return
//    }
//
//private:
//    std::vector< Vertex* > m_vertices;
//    std::vector< Edge* > m_edges;
//
//};

}

#endif // BEMO_DAG_HH
