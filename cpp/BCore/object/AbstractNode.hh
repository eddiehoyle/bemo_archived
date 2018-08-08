#ifndef BEMO_ABSTRACTNODE_HH
#define BEMO_ABSTRACTNODE_HH

#include <BCore/Platform.hh>
#include <BCore/internal/Handle.hh>

namespace bemo {

using NodeID = Handle< ObjectType::Node, u32, 16, 16 >;
using NodeTypeID = std::string;

class AbstractNode {

    friend class NodeManager;

public:

    static constexpr ObjectType OBJECT_TYPE_ID = { ObjectType::Node };

public:
    AbstractNode()
        : m_nodeID( NodeID::INVALID_HANDLE ),
          m_typeID() { BMO_ERROR << "ctor"; }
    virtual ~AbstractNode() { BMO_ERROR << "dtor"; }

    inline NodeID nodeID() const { return m_nodeID; }
    inline NodeTypeID typeID() const { return m_typeID; }
    bool isValid() const;
    virtual int execute();

private:
    NodeID m_nodeID;
    NodeTypeID m_typeID;
};

}

#endif // BEMO_ABSTRACTNODE_HH
