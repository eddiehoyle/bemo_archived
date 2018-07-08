#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include <vector>
#include "Node.hh"

namespace bemo {

class Graph;
using GraphPtr = std::shared_ptr< Graph >;

GraphPtr create_graph();

class Graph {
public:
    void add( NodePtr node );
    void remove( NodePtr node );
    std::size_t get_count() const;
    int execute();
private:
    std::vector< NodePtr > m_nodes;
};

class GraphManager {
public:
    GraphManager();
    GraphPtr get_graph();
private:
    GraphPtr m_graph;
};

}

#endif // BEMO_GRAPH_HH