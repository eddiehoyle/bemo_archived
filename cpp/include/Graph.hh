#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include <vector>
#include <Node.hh>

namespace bemo {

class Graph {
public:
    void add( const Node& node );
    void remove( const Node& node );
    std::size_t get_count() const;
private:
    std::vector< Node > m_nodes;
};

}

#endif // BEMO_GRAPH_HH