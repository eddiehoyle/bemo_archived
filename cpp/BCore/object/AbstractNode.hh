#ifndef BEMO_ABSTRACTNODE_HH
#define BEMO_ABSTRACTNODE_HH

#include <BCore/Platform.hh>
#include <BCore/internal/Handle.hh>

namespace bemo {

using NodeID = Handle< u32, 16, 16 >;
using NodeTypeID = std::string;

class AbstractNode {

    friend class NodeManager;

public:
    AbstractNode()
        : m_nodeID( NodeID::INVALID_HANDLE ),
          m_typeID() { BMO_ERROR << "ctor"; }
    virtual ~AbstractNode() { BMO_ERROR << "dtor"; }
    virtual int execute() { return -1; }
    NodeID nodeID() const { return m_nodeID; }
    NodeTypeID typeID() const { return m_typeID; }
private:
    NodeID m_nodeID;
    NodeTypeID m_typeID;
};

}

#endif // BEMO_ABSTRACTNODE_HH
