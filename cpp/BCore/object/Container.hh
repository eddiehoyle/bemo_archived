#ifndef BEMO_ABSTRACTCONTAINER_HH
#define BEMO_ABSTRACTCONTAINER_HH

#include "Object.hh"
#include "Plug.hh"

#include <BCore/API.hh>
#include <BCore/Variant.hh>
#include <BCore/managers/PlugManager.hh>

namespace bemo {

template< typename T >
class Container : public Object< T > {
public:
    int getInput( const std::string& name ) { return int( 0 ); }
    void setOutput( const std::string& name, int value ) {}
protected:
    explicit Container( ObjectID id ) : Object< T >( id ) {}
    virtual int execute() = 0;
protected:
    ObjectID m_layoutID;
};

}

#endif // BEMO_ABSTRACTCONTAINER_HH
