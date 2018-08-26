#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include <vector>
#include <BCore/internal/Object.hh>

namespace bemo {

class Graph {

    friend class GraphManager;

public:
    Graph() = default;
    int execute() { return -1; }
private:
    ObjectID m_id;
    std::vector< ObjectID > m_nodes;
};

}

#endif // BEMO_GRAPH_HH