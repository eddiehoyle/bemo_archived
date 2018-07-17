#ifndef BEMO_GRAPHMANAGER_HH
#define BEMO_GRAPHMANAGER_HH

#include "ContainerManager.hh"
#include <BCore/object/Graph.hh>

namespace bemo {

class GraphManager : public ContainerManager< Graph, GraphID > {
public:
    Graph create() { return Graph( GraphID::INVALID_HANDLE ); }

};

}
#endif // BEMO_GRAPHMANAGER_HH
