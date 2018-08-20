#include "AbstractNode.hh"

#include <BCore/API.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/PlugManager.hh>

namespace bemo {

AbstractNode::AbstractNode()
        : m_id(),
          m_nodeType( "invalid" ) {}

AbstractNode::~AbstractNode() {
    BMO_NodeManager->remove( getID() );
}

Plug* AbstractNode::getPlug( const std::string& name ) {
    return BMO_PlugManager->find( name );
}


}