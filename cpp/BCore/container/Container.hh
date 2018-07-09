#ifndef BEMO_CONTAINER_HH
#define BEMO_CONTAINER_HH

#include "AbstractContainer.hh"
#include <BCore/internal/ObjectType.hh>

#include <string>
#include <memory>
#include <iostream>

namespace bemo {

template< typename C >
class Container : public AbstractContainer {

protected:
    virtual int _execute() { return 0; };

protected:
    static const ContainerTypeID m_typeID;

};

template< typename C >
const bemo::ContainerID Container< C >::m_typeID =
        bemo::internal::ObjectTypeID< bemo::AbstractContainer >::allocate<C>();

}

#endif // BEMO_CONTAINER_HH