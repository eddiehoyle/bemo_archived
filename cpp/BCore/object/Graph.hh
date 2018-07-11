#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include "Container.hh"

namespace bemo {

/// Top level container used as an execution entry point.
class Graph : public Container< Graph > {
public:
    explicit Graph( ObjectID id ) : Container( id ) {}
    ~Graph() override = default;
};

}

#endif // BEMO_GRAPH_HH