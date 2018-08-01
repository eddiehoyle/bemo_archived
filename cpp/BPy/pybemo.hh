#ifndef BEMO_PYNODE_HH
#define BEMO_PYNODE_HH

#include <memory>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <vector>

namespace bemo {
//
//class BaseNode;
//class NodeManager;
//class NodeRegister;
//
//using CreateFunc = std::function< BaseNode*() >;
//using NodePtr = std::shared_ptr< BaseNode >;
//
//class BaseNode {
//
//    friend class NodeManager;
//
//public:
//    explicit BaseNode( int value );
//    virtual ~BaseNode() = default;
//    int value() const;
//    std::string typeID() const;
//    int nodeID() const;
//private:
//    int m_nodeID;
//    std::string m_typeID;
//    int m_value;
//};
//
//class CppNode : public BaseNode {
//public:
//    using BaseNode::BaseNode;
//};
//
//class NodeManager {
//public:
//    NodeManager();
//    void add( const std::string& type, CreateFunc func );
//    BaseNode* create( const std::string& type );
//private:
//    std::map< std::string, CreateFunc > m_creators;
//    std::vector< BaseNode* > m_nodes;
//};

}

#endif // BEMO_PYNODE_HH
