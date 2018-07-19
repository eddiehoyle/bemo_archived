#ifndef BEMO_PLUGMANAGER_HH
#define BEMO_PLUGMANAGER_HH

#include "AbstractManager.hh"
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractObject.hh>

namespace bemo {

class PlugManager : public AbstractManager< Plug > {

    using OwnerID = ObjectID;
    using PlugIDs = std::vector< ObjectID >;

public:
    Plugs getPlugs( ObjectID owner ) {
        Plugs plugs;
        auto iter = m_plugMap.find( owner );
        if ( iter != m_plugMap.end() ) {
            for ( ObjectID plugID : iter->second ) {
                plugs.push_back( Plug( plugID ) );
            }
        }
        return plugs;
    }

private:
    std::map< OwnerID, PlugIDs > m_plugMap;

};


}

#endif // BEMO_PLUGMANAGER_HH
