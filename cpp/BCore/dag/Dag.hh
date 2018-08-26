#ifndef BEMO_DAG_HH
#define BEMO_DAG_HH

#include <BCore/internal/Object.hh>

namespace bemo {

struct Vertex;
struct Edge;

struct Vertex {
    Edge* input;
    Edge* output;
    ObjectID m_id;
};

struct Edge {
    Vertex* input;
    Vertex* output;
};

struct Dag {

public:
    void connect( const ObjectID& source, const ObjectID& target ) {
        auto sourceVertexIter = std::find_if( m_vertices.begin(),
                                              m_vertices.end(),
                                              [&]( Vertex* vertex ) {
                                                  return vertex->m_id == source;
                                              });
        auto targetVertexIter = std::find_if( m_vertices.begin(),
                                              m_vertices.end(),
                                              [&]( Vertex* vertex ) {
                                                  return vertex->m_id == target;
                                              });
    }

    ObjectID get_vertices() const {
        return
    }

private:
    std::vector< Vertex* > m_vertices;
    std::vector< Edge* > m_edges;

};

}

#endif // BEMO_DAG_HH
