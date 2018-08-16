#ifndef BEMO_PLUGMANAGER_HH
#define BEMO_PLUGMANAGER_HH

#include "AbstractManager.hh"
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractObject.hh>

namespace bemo {

class PlugManager {

public:

    template< typename... Args >
    PlugID create( Args&&... args ) {
//        PlugID id = m_table.acquire( new Plug( std::forward<Args>( args )... ) );
//        Plug* plug = m_table[ id ];
//        plug->m_id = id;
        return PlugID( 0 );
    }

//    Plug* get( PlugID id ) const {
//        return m_table[ id ];
//    }

    PlugID find( const PlugName& name ) {
        return PlugID( 0 );
    }

private:
    HandleTable< PlugID > m_table;
};


}

#endif // BEMO_PLUGMANAGER_HH
