#ifndef BEMO_CONTAINER_HH
#define BEMO_CONTAINER_HH

#include "AbstractManagedObject.hh"
#include <BCore/internal/ObjectType.hh>

namespace bemo {

template< typename T >
class Container : public AbstractManagedObject {
public:
    static const TypeID typeID;
protected:
    explicit Container( ObjectID id ) : AbstractManagedObject( id ) {}
    ~Container() override = default;
    virtual int execute() { return 0; };
};

template< typename T >
const bemo::TypeID Container< T >::typeID =
        bemo::internal::ObjectTypeID< bemo::AbstractManagedObject >::allocate< T >();

}

#endif // BEMO_CONTAINER_HH