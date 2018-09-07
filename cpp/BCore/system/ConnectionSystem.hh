#ifndef BEMO_CONNECTIONSYSTEM_HH
#define BEMO_CONNECTIONSYSTEM_HH

#include <BCore/Bemo.hh>
#include <BCore/managers/ConnectionManager.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/dag/DagManager.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractNode.hh>

namespace bemo {

class ConnectionSystem {
public:
    explicit ConnectionSystem( const ObjectID& id ) : m_id( id ) {}

    void connect( const PlugName& sourceName,
                  const ObjectID& targetID,
                  const PlugName& targetName ) {
        Plug* sourcePlug = BMO_PlugManager->find( m_id, sourceName, PlugDirectionPolicy::Output );
        Plug* targetPlug = BMO_PlugManager->find( targetID, targetName, PlugDirectionPolicy::Input );
        if ( sourcePlug && targetPlug ) {
            if ( BMO_DependencyGraph->canConnect( sourcePlug->getID(), targetPlug->getID() ) ) {
                BMO_ConnectionManager->create( sourcePlug->getID(), targetPlug->getID() );
            }
        }
    }

    void disconnect( const PlugName& sourceName,
                     const ObjectID& targetID,
                     const PlugName& targetName ) {
        BMO_ERROR << "disconnecting " << sourceName;
        Plug* sourcePlug = BMO_PlugManager->find( m_id, sourceName, PlugDirectionPolicy::Output );
        Plug* targetPlug = BMO_PlugManager->find( targetID, targetName, PlugDirectionPolicy::Input );
        if ( sourcePlug && targetPlug ) {
            Connection* connection = BMO_ConnectionManager->find( sourcePlug->getID(), targetPlug->getID() );
            if ( connection ) {
                BMO_ConnectionManager->remove( connection->getID() );
            }
        }
    }

    bool isConnected( const PlugName& sourcePlugName ) const {

        bool result = false;

//        Plug* plug = BMO_PlugManager->find( m_nodeID, sourcePlugName,  );
//        if ( plug ) {
//            const std::vector< Connection* > connections = BMO_ConnectionManager->find( plug->getID() );
//            result = !connections.empty();
//        }

        return result;
    }

private:
    ObjectID m_id;
};

}

#endif // BEMO_CONNECTIONSYSTEM_HH
