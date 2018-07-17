#ifndef BEMO_CONNECTION_HH
#define BEMO_CONNECTION_HH

#include "AbstractObject.hh"
#include <BCore/internal/ObjectType.hh>

namespace bemo {

/// No templates necessary here
class Connection : public AbstractObject {
public:
    static const TypeID typeID;
protected:
    explicit Connection( ObjectID id ) : AbstractObject( id ) {}
    ~Connection() override = default;
    virtual int execute() {};
};

const bemo::TypeID Connection::typeID =
        bemo::internal::ObjectTypeID< bemo::AbstractObject >::allocate< Connection >();

}

#endif // BEMO_CONNECTION_HH
