#ifndef BEMO_PLUG_HH
#define BEMO_PLUG_HH

#include "Object.hh"

#include <vector>

namespace bemo {

class Plug;

using Plugs = std::vector< Plug >;

enum class Direction {
    Input,
    Output,
};

class Plug : public Object< Plug > {
public:

//    /// TODO
//    bool isConnected() const {
//        return BMO_ConnectionManager->has( objectID() );
//    }

//    /// TODO
//    Connection getConnection() const {
//        return BMO_ConnectionManager->get( objectID() );
//    }

//    /// TODO
//    void connect( const Plug& plug ) {
//        ObjectID sourceOwnerID = BMO_PlugManager->getOwner( this->objectID() );
//        ObjectID targetOwnerID = BMO_PlugManager->getOwner( plug.objectID() );
//        if ( sourceOwnerID && targetOwnerID ) {
//            BMO_ConnectionManager->connect( sourceOwnerID, this->objectID(),
//                                            targetOwnerID, plug.objectID() );
//        }
//    }

private:
    Direction m_direction;
};

}

#endif // BEMO_PLUG_HH
