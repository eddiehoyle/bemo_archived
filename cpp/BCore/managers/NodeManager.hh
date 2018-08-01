#ifndef BEMO_NODEMANAGER_HH
#define BEMO_NODEMANAGER_HH

#include <BCore/API.hh>
#include <BCore/internal/Table.hh>
#include <BCore/object/AbstractNode.hh>
#include <BCore/managers/NodeRegistry.hh>

namespace bemo {

class NodeManager {
public:
    AbstractNode* create( const std::string& type ) {
        auto func = BMO_NodeRegistry->find( type );
        NodeID id = m_table.acquire( func() );
        AbstractNode* node = m_table[ id ];
        node->m_nodeID = id;
        node->m_typeID = type;
        return node;
    }
private:
    HandleTable< AbstractNode, NodeID > m_table;
};

}
#endif // BEMO_NODEMANAGER_HH
