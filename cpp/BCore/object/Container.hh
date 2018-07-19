#ifndef BEMO_ABSTRACTCONTAINER_HH
#define BEMO_ABSTRACTCONTAINER_HH

#include "Object.hh"
#include "Plug.hh"

#include <BCore/API.hh>
#include <BCore/managers/PlugManager.hh>

namespace bemo {

template< typename T >
class Container : public Object< T > {
public:
    Plugs getInputPlugs() const {
        return BMO_PlugManager->getPlugs( this->m_objectID );
    }

protected:
    explicit Container( ObjectID id ) : Object< T >( id ) {}
    virtual int execute() = 0;
};

}

#endif // BEMO_ABSTRACTCONTAINER_HH
