#ifndef BEMO_NODE_HH
#define BEMO_NODE_HH

#include <string>
#include <memory>
#include <iostream>

namespace bemo {

class Node;
using NodePtr = std::shared_ptr< Node >;

NodePtr create_node( const std::string& name );
std::string read_node( const NodePtr& node );

class AbstractNode {
public:
    virtual ~AbstractNode() = default;
public:
    int execute() {
        return _execute();
    }
protected:
    virtual int _execute() = 0;
};

class Node : public AbstractNode {
public:
    virtual ~Node() = default;
    explicit Node( const std::string& name );
    bool operator==( const Node& n );
    void set_name( const std::string& name );
    std::string get_name() const;
protected:
    virtual int _execute() { return 0; }
private:
    std::string m_name;
};

}

#endif // BEMO_NODE_HH