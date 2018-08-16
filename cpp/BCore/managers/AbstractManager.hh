#ifndef BEMO_ABSTRACTMANAGER_HH
#define BEMO_ABSTRACTMANAGER_HH

#include <BCore/internal/Handle.hh>
#include <BCore/internal/Object.hh>
#include <BCore/internal/Table.hh>

namespace bemo {

class ObjectManager {
public:
    BObject acquire( ObjectType type ) {
        BObject obj;
        obj.m_handle = m_table.acquire();
        return obj;
    }
private:
    HandleTable< ObjectID > m_table;
};

}

#endif // BEMO_ABSTRACTMANAGER_HH
