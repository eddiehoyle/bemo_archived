#ifndef BEMO_PLUGMANAGER_HH
#define BEMO_PLUGMANAGER_HH

#include "ObjectManager.hh"
#include <BCore/object/Plug.hh>
#include <BCore/internal/Object.hh>
#include <BCore/object/AbstractObject.hh>

namespace bemo {

class PlugManager {

public:

    template< typename... Args >
    ObjectID create( Args&&... args ) {
//        ObjectID id = m_table.acquire( new Plug( std::forward<Args>( args )... ) );
//        Plug* plug = m_table[ id ];
//        plug->m_id = id;
        return ObjectID();
    }
};


}

#endif // BEMO_PLUGMANAGER_HH
