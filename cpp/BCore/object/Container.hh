#ifndef BEMO_ABSTRACTCONTAINER_HH
#define BEMO_ABSTRACTCONTAINER_HH

#include "Object.hh"

namespace bemo {

template< typename T, typename H >
class Container : public Object< T, H > {
protected:
    explicit Container( typename AbstractObject< T, H >::HandleType id ) : Object< T, H >( id ) {}
    virtual void execute() = 0;
};

}

#endif // BEMO_ABSTRACTCONTAINER_HH
