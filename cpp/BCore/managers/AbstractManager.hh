#ifndef BEMO_ABSTRACTMANAGER_HH
#define BEMO_ABSTRACTMANAGER_HH

#include <BCore/internal/Table.hh>
#include <BCore/object/AbstractObject.hh>

namespace bemo {
//
//template< typename T >
//class AbstractManager {
//
//    using Object = T;
//
//public:
//    Object create() {
//        ObjectID id = this->m_table.acquire( nullptr );
//        return T( id );
//    }
//    void release( T object ) {
//        this->m_table.release( object.objectID() );
//    }
//
//protected:
//
//    AbstractManager() = default;
//    ~AbstractManager() = default;
//
//    HandleTable< Object, ObjectID > m_table;
//};

}

#endif // BEMO_ABSTRACTMANAGER_HH
