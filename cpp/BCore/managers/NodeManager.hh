#ifndef BEMO_NODEMANAGER_HH
#define BEMO_NODEMANAGER_HH

#include "AbstractManager.hh"
#include <BCore/object/Node.hh>

namespace bemo {

class NodeManager : public AbstractManager< Node > {
public:

    template< typename T >
    T createNode() {
        ObjectID id = this->m_table.acquire( nullptr );
        return T( id );
    }
//    Node create( const std::string& name ) {

        // 1. Find nodeTypeID for name
        // 2. Find nodeLayoutID for name
        // 3. If both valid, create Node and set ID's
//        auto nodeIter = m_nodeTypes.find( name );
//        auto layoutIter = m_nodeLayouts.find( name );

//        TypeID nodeTypeID = BMO_NodeRegistry->find( name );
//        if ( nodeTypeID != INVALID_TYPE_ID ) {
//
//            ObjectID nodeID = create();
//            ObjectID layoutID = BMO_LayoutManager->create( nodeTypeID );
//
//            Node node = get( nodeID );
//            node.m_nodeTypeID = nodeTypeID;
//            node.m_layoutID = layoutID;
//
//            return node;
//        }
//        return Node( ObjectID::invalid() );
//    }

//    Node createNode( const std::string& name ) {
//        TypeID nodeTypeID = BMO_NodeRegistry->get( name );
//        TypeID layoutTypeID = BMO_LayoutRegistry->get( nodeTypeID );
//        Node node = create( nodeTypeID );

        // 1. Look up name -> nodeTypeID
        // 2. Create Node

//        return node;
//    }
private:
    std::map< std::string, TypeID > m_nodeTypes;
    std::map< std::string, TypeID > m_nodeLayouts;
};

}
#endif // BEMO_NODEMANAGER_HH
