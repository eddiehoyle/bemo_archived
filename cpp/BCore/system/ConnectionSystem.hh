#ifndef BEMO_CONNECTIONSYSTEM_HH
#define BEMO_CONNECTIONSYSTEM_HH

#include <BCore/API.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractNode.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/ConnectionManager.hh>

namespace bemo {

class ConnectionSystem {
public:
    explicit ConnectionSystem( const ObjectID& id ) : m_id( id ) {}

    void connect( const PlugName& sourceName,
                  const ObjectID& targetID,
                  const PlugName& targetName ) {
        BMO_ERROR << "connecting " << m_id << " --> " << targetID;
        Plug* sourcePlug = BMO_PlugManager->find( m_id, sourceName );
        Plug* targetPlug = BMO_PlugManager->find( targetID, targetName );
        BMO_ERROR << "found plugs! source=" << sourceName << ", valid="
                  << ( sourcePlug != nullptr ) << ", target=" << targetName
                  << ", valid=" << ( targetPlug != nullptr );
        if ( sourcePlug && targetPlug ) {
            BMO_ConnectionManager->create( sourcePlug->getID(),
                                           targetPlug->getID() );
        }
    }

    void disconnect( const PlugName& sourceName,
                     const ObjectID& targetID,
                     const PlugName& targetName ) {
        BMO_ERROR << "disconnecting " << sourceName;
        Plug* sourcePlug = BMO_PlugManager->find( m_id, sourceName );
        Plug* targetPlug = BMO_PlugManager->find( targetID, targetName );
        if ( sourcePlug && targetPlug ) {
            Connection* connection = BMO_ConnectionManager->find( sourcePlug->getID(), targetPlug->getID() );
            if ( connection ) {
                BMO_ConnectionManager->remove( connection->getID() );
            }
        }
    }

    bool isConnected( const PlugName& sourcePlugName ) const {

        bool result = false;

        Plug* plug = BMO_PlugManager->find( m_id, sourcePlugName );
        if ( plug ) {
            const std::vector< Connection* > connections = BMO_ConnectionManager->find( plug->getID() );
            result = !connections.empty();
        }

        return result;
    }

private:
    ObjectID m_id;
};

}

#endif // BEMO_CONNECTIONSYSTEM_HH
