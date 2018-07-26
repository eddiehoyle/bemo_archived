#ifndef BEMO_NODE_HH
#define BEMO_NODE_HH

#include "AbstractNode.hh"

#include <BCore/Platform.hh>
#include <BCore/internal/Handle.hh>
#include <BCore/Defs.hh>
#include <BCore/internal/ObjectType.hh>

namespace bemo {

using NodeTypeID = TypeID;

template< NodeType node_type >
class Node : public AbstractNode {
public:
    static const NodeTypeID NODE_TYPE_ID = { static_cast< NodeTypeID >( node_type ) };
public:
    NodeTypeID nodeTypeID() const { return NODE_TYPE_ID; }

};

} // namespace bemo

#endif // BEMO_NODE_HH
