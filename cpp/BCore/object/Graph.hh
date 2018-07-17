#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include "Container.hh"

namespace bemo {

using GraphID = ObjectID;

class Graph : public Container< Graph, GraphID > {
public:
    explicit Graph( GraphID id ) : Container< Graph, GraphID >( id ) {}
    void execute() {}
};

}

#endif // BEMO_GRAPH_HH