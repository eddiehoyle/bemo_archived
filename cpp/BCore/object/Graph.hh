#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include <BCore/internal/Handle.hh>
#include "Container.hh"

namespace bemo {

using GraphID = Handle32;

class Graph : public Container< Graph, GraphID > {

public:
    explicit Graph( GraphID id ) : Container< Graph, GraphID >( id ) {}
    ~Graph() override = default;
};

}

#endif // BEMO_GRAPH_HH