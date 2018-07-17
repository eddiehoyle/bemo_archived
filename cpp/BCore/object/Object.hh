#ifndef BEMO_CONTAINER_HH
#define BEMO_CONTAINER_HH

#include "AbstractObject.hh"
#include <BCore/internal/ObjectType.hh>

namespace bemo {

template< typename T, typename H >
class Object : public AbstractObject< T, H > {
public:
    static TypeID typeID() { return m_typeID; }
protected:
    explicit Object( typename AbstractObject< T, H >::HandleType id ) : AbstractObject< T, H >( id ) {}
    ~Object() override = default;
private:
    static const TypeID m_typeID;
};

template< typename T, typename H >
const bemo::TypeID Object< T, H >::m_typeID =
        bemo::internal::ObjectTypeID< bemo::AbstractObject< T, H > >::template allocate< T >();

}

#endif // BEMO_CONTAINER_HH