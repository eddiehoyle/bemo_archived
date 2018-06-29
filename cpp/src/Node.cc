#include <Node.hh>
#include <memory>

namespace bemo {

NodePtr create_node( const std::string& name ) {
    return std::make_shared<Node>( name );
}

std::string read_node( const NodePtr& node ) {
    return node->get_name();
}

Node::Node( const std::string& name )
        : m_name( name ) {}

bool Node::operator==( const Node& n ) {
    return this->m_name == n.m_name;
}

void Node::set_name( const std::string& name ) {
    m_name = name;
}

std::string Node::get_name() const {
    return m_name;
}


}