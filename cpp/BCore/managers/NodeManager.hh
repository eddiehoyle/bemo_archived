#ifndef BEMO_NODEMANAGER_HH
#define BEMO_NODEMANAGER_HH

#include <BCore/API.hh>
#include <BCore/internal/Table.hh>
#include <BCore/object/AbstractNode.hh>

namespace bemo {

class NodeManager {
public:
    NodeID acquire( const std::string& type, AbstractNode* node ) {
//        auto func = BMO_NodeRegistry->find( type );
//        NodeID id = m_table.acquire( func() );
//        AbstractNode* node = m_table[ id ];
        NodeID id( 0 );
        node->m_nodeID = id;
        node->m_typeID = type;
        return id;
    }
private:
    HandleTable< AbstractNode, NodeID > m_table;
};

}
#endif // BEMO_NODEMANAGER_HH
