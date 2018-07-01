#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include <vector>
#include <Node.hh>

namespace bemo {

class Graph;
using GraphPtr = std::shared_ptr< Graph >;

GraphPtr create_graph() {
    return std::make_shared< Graph >();
}

class Graph {
public:
    void add( NodePtr node );
    void remove( NodePtr node );
    std::size_t get_count() const;
    int execute() {
        for ( NodePtr node : m_nodes ) {
            int rc = node->execute();
            if ( rc != 0 ) {
                break;
            }
        }
        return 0;
    }
private:
    std::vector< NodePtr > m_nodes;
};

class GraphManager {
public:
    GraphManager() : m_graph( nullptr ) {
        m_graph = create_graph();
    }
    static GraphManager& instance() {
        static GraphManager instance;
        std::cerr << "got instance=" << (void*)&instance << std::endl;
        return instance;
    }
    GraphPtr graph() {
        return m_graph;
    }
private:
    GraphPtr m_graph;
};

bemo::GraphPtr get_ui_graph() {
    GraphPtr graph = GraphManager::instance().graph();
    std::cerr << "got graph=" << (void*)graph.get() << std::endl;
    return graph;
}

}

#endif // BEMO_GRAPH_HH