#ifndef BEMO_PLUGIN_HH
#define BEMO_PLUGIN_HH

#include "Object.hh"

namespace bemo {

class Plugin : public Object< Plugin > {
public:
    explicit Plugin( ObjectID id ) : Object< Plugin >( id ) {}
private:
    Direction m_direction;
};

}


#endif // BEMO_PLUGIN_HH
