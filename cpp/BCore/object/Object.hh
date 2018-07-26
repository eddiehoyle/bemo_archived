#ifndef BEMO_CONTAINER_HH
#define BEMO_CONTAINER_HH

#include "AbstractObject.hh"
#include <BCore/internal/ObjectType.hh>

namespace bemo {

template< typename T >
class Object : public AbstractObject {
public:
    static TypeID typeID() { return m_typeID; }
protected:
    ~Object() override = default;
private:
    static const TypeID m_typeID;
};

template< typename T >
const bemo::TypeID Object< T >::m_typeID =
        bemo::internal::ObjectTypeID< bemo::AbstractObject >::template allocate< T >();

}

#endif // BEMO_CONTAINER_HH