#include "Graph.hh"
#include "Node.hh"
#include "util/Log.hh"

namespace bemo {

GraphPtr create_graph() {
    return std::make_shared< Graph >();
}

void Graph::add( NodePtr node ) {
    m_nodes.push_back( node );
}

void Graph::remove( NodePtr node ) {
    auto iter = std::find( m_nodes.begin(), m_nodes.end(), node );
    if ( iter != m_nodes.end() ) {
        m_nodes.erase( iter );
    }
}

int Graph::execute() {
    for ( NodePtr node : m_nodes ) {
        int rc = node->execute();
        if ( rc != 0 ) {
            break;
        }
    }
    return 0;
}

std::size_t Graph::get_count() const {
    return m_nodes.size();
}

GraphManager::GraphManager()
    : m_graph( nullptr ) {
    BMO_ERROR << "Created GraphManager=" << (void*)this;
    m_graph = create_graph();
}

GraphPtr GraphManager::get_graph() {
    return m_graph;
}

}