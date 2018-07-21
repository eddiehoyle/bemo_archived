#ifndef BEMO_NODEMANAGER_HH
#define BEMO_NODEMANAGER_HH

#include "AbstractManager.hh"
#include <BCore/object/Node.hh>

namespace bemo {

class NodeManager : public AbstractManager< Node > {
public:

    Node create( const std::string& name ) {
        TypeID nodeTypeID = BMO_NodeRegistry->find( name );
        if ( nodeTypeID != INVALID_TYPE_ID ) {
            ObjectID nodeID = create();
            ObjectID layoutID = BMO_LayoutManager->create();

            Node node = get( nodeID );
            node.m_nodeTypeID = nodeTypeID;
            node.m_layoutID = layoutID;
            return node;
        }
        return Node( ObjectID::invalid() );
    }

    Node createNode( const std::string& name ) {
        TypeID nodeTypeID = BMO_NodeRegistry->get( name );
//        TypeID layoutTypeID = BMO_LayoutRegistry->get( nodeTypeID );
        Node node = create( nodeTypeID );

        // 1. Look up name -> nodeTypeID
        // 2. Create Node

        return node;
    }
};

}
#endif // BEMO_NODEMANAGER_HH
