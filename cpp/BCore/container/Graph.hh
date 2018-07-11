#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include <vector>
#include "Container.hh"
#include <BCore/API.hh>
#include <BCore/managers/ContainerManager.hh>

namespace bemo {

/// Top level container used as an execution entry point.
class Graph : public Container< Graph > {
public:
    explicit Graph( ContainerID id ) : Container( id ) {}
    ~Graph() override = default;
};

}

#endif // BEMO_GRAPH_HH