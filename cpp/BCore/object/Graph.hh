#ifndef BEMO_GRAPH_HH
#define BEMO_GRAPH_HH

#include "Object.hh"

namespace bemo {

class BDagGraph : public Object {
public:
    static constexpr ObjectType OBJECT_TYPE = { ObjectType::kGraph };
public:
    virtual void initialise() = 0;
};

}

#endif // BEMO_GRAPH_HH
