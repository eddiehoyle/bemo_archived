#ifndef BEMO_NODEMANAGER_HH
#define BEMO_NODEMANAGER_HH

#include <BCore/API.hh>
#include <BCore/internal/Table.hh>
#include <BCore/object/AbstractNode.hh>

namespace bemo {

class NodeManager {
public:
    NodeID acquire( const std::string& type, AbstractNode* node ) {
        NodeID id( static_cast< u32 >( m_objectIDs.size() ) );
        node->m_nodeID = id;
        node->m_typeID = type;
        m_objectIDs.insert( id );
        return id;
    }
    inline bool has( const NodeID& id ) {
        return m_objectIDs.find( id ) != m_objectIDs.end();
    }
private:
    std::set< NodeID > m_objectIDs;
};

template< typename T, typename C, typename L >
class NodeManager2 {
public:

private:
};

}
#endif // BEMO_NODEMANAGER_HH
