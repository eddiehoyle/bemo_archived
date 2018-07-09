#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include <vector>
#include "Container.hh"

namespace bemo {

class Graph;
using GraphPtr = std::shared_ptr< Graph >;

/// Top level container used as an execution entry point.
class Graph : public Container< Graph > {
};

}

#endif // BEMO_GRAPH_HH