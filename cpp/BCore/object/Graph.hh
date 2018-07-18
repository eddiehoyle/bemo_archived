#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include "Container.hh"

namespace bemo {

class Graph : public Container< Graph > {
public:
    explicit Graph( ObjectID id ) : Container< Graph >( id ) {}
    int execute() override { return 0; }
};

}

#endif // BEMO_GRAPH_HH