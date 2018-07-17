#ifndef BEMO_ABSTRACTMANAGER_HH
#define BEMO_ABSTRACTMANAGER_HH

#include <BCore/internal/Table.hh>

namespace bemo {

template< typename T >
class AbstractManager {

    using ObjectType = T;
    using HandleType = typename T::HandleType;

public:
    virtual ObjectType create() {
        HandleType id = this->m_table.acquire( nullptr );
        return ObjectType( id );
    }
    virtual void destroy( HandleType objectID ) {
        this->m_table.release( objectID );
    }

protected:

    AbstractManager() = default;
    ~AbstractManager() = default;

    HandleTable< T > m_table;
};

}

#endif // BEMO_ABSTRACTMANAGER_HH
