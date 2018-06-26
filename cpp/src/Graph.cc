#include <Graph.hh>
#include <Node.hh>

namespace bemo {

void Graph::add( const Node& node ) {
    m_nodes.push_back( node );
}

void Graph::remove( const Node& node ) {
    auto iter = std::find( m_nodes.begin(), m_nodes.end(), node );
    if ( iter != m_nodes.end() ) {
        m_nodes.erase( iter );
    }
}

std::size_t Graph::get_count() const {
    return m_nodes.size();
}

}