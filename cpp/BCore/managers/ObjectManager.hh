#ifndef BEMO_ABSTRACTMANAGER_HH
#define BEMO_ABSTRACTMANAGER_HH

#include <BCore/internal/Handle.hh>
#include <BCore/internal/Object.hh>
#include <BCore/internal/Table.hh>

namespace bemo {

class ObjectManager {
public:
    ObjectID acquire( ObjectType type ) {
        ObjectID obj;
        obj.m_handle = m_table.acquire( type );
        return obj;
    }
    void release( const ObjectID& id ) {
        m_table.release( id.m_handle );
    }

    bool exists( const ObjectID& id ) {
        return m_table.exists( id.m_handle );
    }
private:
    HandleTable< ObjectType, ObjectHandle > m_table;
};

}

#endif // BEMO_ABSTRACTMANAGER_HH
