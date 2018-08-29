#ifndef BEMO_CONNECTIONSYSTEM_HH
#define BEMO_CONNECTIONSYSTEM_HH

#include <BCore/Bemo.hh>
#include <BCore/managers/ConnectionManager.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractNode.hh>

namespace bemo {

class ConnectionSystem {
public:
    explicit ConnectionSystem( const ObjectID& id ) : m_id( id ) {}

    void connect( const PlugName& sourceName,
                  const ObjectID& targetID,
                  const PlugName& targetName ) {
        Plug* sourcePlug = BMO->getPlugManager()->find( m_id, sourceName, PlugDirectionPolicy::Output );
        Plug* targetPlug = BMO->getPlugManager()->find( targetID, targetName, PlugDirectionPolicy::Input );
        if ( sourcePlug && targetPlug ) {
            BMO->getConnectionManager()->create( sourcePlug->getID(),
                                           targetPlug->getID() );
        }
    }

    void disconnect( const PlugName& sourceName,
                     const ObjectID& targetID,
                     const PlugName& targetName ) {
        BMO_ERROR << "disconnecting " << sourceName;
        Plug* sourcePlug = BMO->getPlugManager()->find( m_id, sourceName, PlugDirectionPolicy::Output );
        Plug* targetPlug = BMO->getPlugManager()->find( targetID, targetName, PlugDirectionPolicy::Input );
        if ( sourcePlug && targetPlug ) {
            Connection* connection = BMO->getConnectionManager()->find( sourcePlug->getID(), targetPlug->getID() );
            if ( connection ) {
                BMO->getConnectionManager()->remove( connection->getID() );
            }
        }
    }

    bool isConnected( const PlugName& sourcePlugName ) const {

        bool result = false;

//        Plug* plug = BMO->getPlugManager()->find( m_id, sourcePlugName,  );
//        if ( plug ) {
//            const std::vector< Connection* > connections = BMO->getConnectionManager()->find( plug->getID() );
//            result = !connections.empty();
//        }

        return result;
    }

private:
    ObjectID m_id;
};

}

#endif // BEMO_CONNECTIONSYSTEM_HH
