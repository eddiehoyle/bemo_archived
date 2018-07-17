#ifndef BEMO_CONTAINER_HH
#define BEMO_CONTAINER_HH

#include "AbstractObject.hh"
#include <BCore/internal/ObjectType.hh>

namespace bemo {

template< typename T, typename H >
class Container : public AbstractObject< T, H > {

    using ObjectType = T;
    using HandleType = H;

public:
    static TypeID typeID() { return m_typeID; }
protected:
    explicit Container( HandleType id ) : AbstractObject< T, H >( id ) {}
    ~Container() override = default;
    virtual int execute() { return 0; };
private:
    static const TypeID m_typeID;
};

template< typename T, typename H >
const bemo::TypeID Container< T, H >::m_typeID =
        bemo::internal::ObjectTypeID< bemo::AbstractObject< T, H > >::template allocate< T >();

}

#endif // BEMO_CONTAINER_HH