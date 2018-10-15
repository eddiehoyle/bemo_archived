#ifndef BEMO_NODE_HH
#define BEMO_NODE_HH

#include "Object.hh"

namespace bemo {

class BDagNode : public Object {
public:
    static constexpr ObjectType OBJECT_TYPE = { ObjectType::Graph };
public:
    explicit BDagNode( ObjectID id ) : Object( id ) {}
    virtual int execute() = 0;
};

}
#endif // BEMO_NODE_HH
