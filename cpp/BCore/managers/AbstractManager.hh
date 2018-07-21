#ifndef BEMO_ABSTRACTMANAGER_HH
#define BEMO_ABSTRACTMANAGER_HH

#include <BCore/internal/Table.hh>
#include <BCore/object/AbstractObject.hh>

namespace bemo {

template< typename T >
class AbstractManager {

    using Object = T;

public:
    Object create() {
        ObjectID id = this->m_table.acquire( nullptr );
        return id;
    }
    void release( ObjectID id ) {
        this->m_table.release( id );
    }

protected:

    AbstractManager() = default;
    ~AbstractManager() = default;

    HandleTable< Object, ObjectID > m_table;
};

}

#endif // BEMO_ABSTRACTMANAGER_HH
