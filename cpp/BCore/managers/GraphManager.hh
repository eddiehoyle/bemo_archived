#ifndef BEMO_GRAPHMANAGER_HH
#define BEMO_GRAPHMANAGER_HH

#include <BCore/Bemo.hh>
#include <BCore/managers/ObjectManager.hh>
#include <BCore/object/Graph.hh>

namespace bemo {


class GraphManager {

public:

    ObjectID create() {
        ObjectID id = BMO_ObjectManager->acquire( ObjectType::Graph );
        Graph* graph = new Graph();
        graph->m_id = id;
        m_Graphs.push_back( graph );
        return id;
    }

private:
    std::vector< Graph* > m_Graphs;
};

}

#endif // BEMO_GRAPHMANAGER_HH
