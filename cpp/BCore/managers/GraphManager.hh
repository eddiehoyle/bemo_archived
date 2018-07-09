#ifndef BEMO_GRAPHMANAGER_HH
#define BEMO_GRAPHMANAGER_HH

#include <BCore/container/Graph.hh>

namespace bemo {

using GraphWeakPtr = std::weak_ptr< Graph >;

/// Manager to track and operate on active graph.
class GraphManager {
public:
    ~GraphManager() = default;
    void setActive( GraphPtr graph );
    GraphPtr getActive() const;
private:
    GraphWeakPtr m_active;
};

}

#endif // BEMO_GRAPHMANAGER_HH
