#include "AbstractNode.hh"

#include <BCore/API.hh>
#include <BCore/managers/NodeManager.hh>

namespace bemo {

bool AbstractNode::isValid() const {
    return BMO_NodeManager->has( nodeID() );
}

int AbstractNode::execute() {
    return -1;
}

}