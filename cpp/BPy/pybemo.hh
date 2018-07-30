#ifndef BEMO_PYNODE_HH
#define BEMO_PYNODE_HH

#include <memory>
#include <functional>
#include <list>

namespace bemo {

class BaseNode;
class NodeManager;
class NodeRegister;

using CreateFunc = std::function< BaseNode*() >;
using NodePtr = std::shared_ptr< BaseNode >;

class BaseNode {

    friend class NodeManager;

public:
    explicit BaseNode( int value );
    int value() const;
    int typeID() const;
    int nodeID() const;
private:
    int m_nodeID;
    int m_typeID;
    int m_value;
};

class CppNode : public BaseNode {
public:
    using BaseNode::BaseNode;
};

class NodeManager {
public:
    NodeManager();
    void add( const CreateFunc& func );
    NodePtr create();
private:
    std::list< CreateFunc > m_creators;
};

//class MyManager {
//
//    using CreateFunc = std::function< std::shared_ptr<BaseA>() >;
//    using NodeMap = std::map< std::string, CreateFunc >;
//
//public:
//
//    void add( const std::string& name, CreateFunc func ) {
//        m_nodes[ name ] = func;
//    }
//
//    std::shared_ptr< BaseA > create( const std::string& name ) {
//        auto iter = m_nodes.find( name );
//        if ( iter != m_nodes.end() ) {
//            BMO_ERROR << "Found node: " << name;
//            auto creator = iter->second;
//            return creator();
//        }
//        return nullptr;
//    }
//
//private:
//    NodeMap m_nodes;
//};


}

#endif // BEMO_PYNODE_HH
