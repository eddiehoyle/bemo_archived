#ifndef BEMO_CONNECTIONMANAGER_HH
#define BEMO_CONNECTIONMANAGER_HH

#include "ObjectManager.hh"
#include <BCore/object/Plug.hh>
#include <BCore/object/Connection.hh>
#include <BCore/internal/Object.hh>

namespace bemo {

class ConnectionManager {

public:

    ObjectID create( const ObjectID& sourceID, const ObjectID& targetID ) {
        ObjectID id = BMO_ObjectManager->acquire( ObjectType::Plug );
        Connection* connection = new Connection( sourceID, targetID );
        connection->m_id = id;
        m_connections.push_back( connection );
        return id;
    }

    Connection* find( const ObjectID& sourceID, const ObjectID& targetID ) const {
        auto iter = std::find_if( m_connections.begin(),
                                  m_connections.end(),
                                  [&]( Connection* connection ) {
                                      return ( sourceID == connection->getSourceID() ) &&
                                             ( targetID == connection->getTargetID() );
                                  });
        return iter != m_connections.end() ? *iter : nullptr;
    }

    Connection* find( const ObjectID& id ) const {
        auto iter = std::find_if( m_connections.begin(),
                                  m_connections.end(),
                                  [id]( Connection* connection ) {
                                      return connection->m_id == id;
                                  });
        return iter != m_connections.end() ? *iter : nullptr;
    }

private:
    std::vector< Connection* > m_connections;
};

}

#endif // BEMO_CONNECTIONMANAGER_HH
