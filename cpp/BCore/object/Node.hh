#ifndef BEMO_NODE_HH
#define BEMO_NODE_HH

#include "Container.hh"

namespace bemo {

class Node : public Container< Node > {
public:
    explicit Node( ObjectID id ) : Container< Node >( id ) {}
    void execute() override {}
};

}

#endif // BEMO_NODE_HH
