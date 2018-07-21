#ifndef BEMO_NODE_HH
#define BEMO_NODE_HH

#include "Container.hh"

namespace bemo {

class Node : public Container< Node > {
//public:
//    static TypeID nodeTypeID() { return m_nodeTypeID; }
public:
    explicit Node( ObjectID id ) : Container< Node >( id ) {}
    int execute() override { return 0; }
//private:
//    static const TypeID m_nodeTypeID;
};

//const bemo::TypeID Node::m_nodeTypeID =
//        bemo::internal::ObjectTypeID< Node >::allocate< Node >();

}

#endif // BEMO_NODE_HH
