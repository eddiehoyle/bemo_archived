#ifndef BEMO_CONNECTION_HH
#define BEMO_CONNECTION_HH

#include "AbstractManagedObject.hh"
#include <BCore/internal/ObjectType.hh>

namespace bemo {

/// No templates necessary here
class Connection : public AbstractManagedObject {
public:
    static const TypeID typeID;
protected:
    explicit Connection( ObjectID id ) : AbstractManagedObject( id ) {}
    ~Connection() override = default;
    virtual int execute() {};
};

const bemo::TypeID Connection::typeID =
        bemo::internal::ObjectTypeID< bemo::AbstractManagedObject >::allocate< Connection >();

}

#endif // BEMO_CONNECTION_HH
