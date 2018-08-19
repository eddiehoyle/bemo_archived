#ifndef BEMO_ABSTRACTCONTAINER_HH
#define BEMO_ABSTRACTCONTAINER_HH

#include "Object.hh"
#include "Plug.hh"

#include <BCore/API.hh>
#include <BCore/Variant.hh>
#include <BCore/managers/PlugManager.hh>

namespace bemo {


class AbstractContainer {

public:
    virtual int execute() = 0;
};

class Container : public AbstractContainer {
public:
    int getInput( const std::string& name ) { return int( 0 ); }
    void setOutput( const std::string& name, int value ) {}
protected:
    virtual int execute() = 0;
protected:
    ObjectHandle m_layoutID;
};

}

#endif // BEMO_ABSTRACTCONTAINER_HH
