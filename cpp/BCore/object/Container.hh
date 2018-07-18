#ifndef BEMO_ABSTRACTCONTAINER_HH
#define BEMO_ABSTRACTCONTAINER_HH

#include "Object.hh"

namespace bemo {

template< typename T >
class Container : public Object< T > {
protected:
    explicit Container( ObjectID id ) : Object< T >( id ) {}
    virtual void execute() = 0;
};

}

#endif // BEMO_ABSTRACTCONTAINER_HH
