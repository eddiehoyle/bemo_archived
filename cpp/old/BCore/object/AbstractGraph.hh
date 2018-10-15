#ifndef BEMO_ABSTRACTGRAPH_HH
#define BEMO_ABSTRACTGRAPH_HH

#include <old/BCore/internal/Object.hh>

namespace bemo {

typedef std::string GraphName;
typedef std::string GraphType;

class AbstractGraph {

    friend class GraphManager;

public:
    AbstractGraph() = default;

    inline bool isValid() const { return m_id != ObjectID(); }
    inline ObjectID getID() const { return m_id; }
    inline GraphName getName() const { return m_graphName; }

    virtual void expand() = 0;

private:
    ObjectID m_id;
    GraphName m_graphName;
    GraphType m_graphType;
};

}

#endif // BEMO_ABSTRACTGRAPH_HH