#include "AbstractNode.hh"

#include <BCore/API.hh>
#include <BCore/managers/NodeManager.hh>

namespace bemo {

AbstractNode::AbstractNode()
        : m_id(),
          m_nodeType( "invalid" ) {}

AbstractNode::~AbstractNode() {
    BMO_NodeManager->remove( getID() );
}

bool AbstractNode::isValid() const {
    return m_id != ObjectID();
}



}