#ifndef BEMO_NODE_HH
#define BEMO_NODE_HH

#include <string>
#include <memory>

namespace bemo {

class Node;
using NodePtr = std::shared_ptr< Node >;

NodePtr create_node( const std::string& name );
std::string read_node( const NodePtr& node );

class Node {
public:
    explicit Node( const std::string& name );
    bool operator==( const Node& n );
    void set_name( const std::string& name );
    std::string get_name() const;
private:
    std::string m_name;
};

}

#endif // BEMO_NODE_HH