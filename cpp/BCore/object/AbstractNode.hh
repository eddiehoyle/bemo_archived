#ifndef BEMO_ABSTRACTNODE_HH
#define BEMO_ABSTRACTNODE_HH

#include <BCore/Platform.hh>
#include <BCore/internal/Handle.hh>

namespace bemo {

using NodeID = Handle< u32, 16, 16 >;
using NodeTypeID = TypeID;

class AbstractNode {

    friend class NodeManager;

public:
    virtual ~AbstractNode() = default;
    virtual int execute() = 0;
    virtual NodeTypeID nodeTypeID() const = 0;
    NodeID objectID() const { return m_nodeID; }
private:
    NodeID m_nodeID;
};

}

#endif // BEMO_ABSTRACTNODE_HH
