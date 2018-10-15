#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include "Object.hh"

namespace bemo {

class BDagGraph : public Object {
public:
    static constexpr ObjectType OBJECT_TYPE = { ObjectType::Node };
public:
    explicit BDagGraph( ObjectID id ) : Object( id ) {}
    virtual void initialise() = 0;
};

}

#endif // BEMO_GRAPH_HH
