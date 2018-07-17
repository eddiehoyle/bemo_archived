#ifndef BEMO_NODE_HH
#define BEMO_NODE_HH

#include "Container.hh"

namespace bemo {

using NodeID = ObjectID;

class Node : public Container< Node, NodeID > {
public:
    explicit Node( NodeID id ) : Container< Node, NodeID >( id ) {}
    void execute() override {}
};

}

#endif // BEMO_NODE_HH
