#ifndef BEMO_ABSTRACTMANAGER_HH
#define BEMO_ABSTRACTMANAGER_HH

#include <BCore/internal/Table.hh>
#include <BCore/object/AbstractObject.hh>

namespace bemo {

template< typename T >
class AbstractManager {

    using ObjectType = T;

public:
    virtual ObjectType create() {
        ObjectID id = this->m_table.acquire( nullptr );
        return ObjectType( id );
    }
    virtual void destroy( ObjectID id ) {
        this->m_table.release( id );
    }

protected:

    AbstractManager() = default;
    ~AbstractManager() = default;

    HandleTable< ObjectType, ObjectID > m_table;
};

}

#endif // BEMO_ABSTRACTMANAGER_HH
