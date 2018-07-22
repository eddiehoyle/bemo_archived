#ifndef BEMO_PLUGIN_HH
#define BEMO_PLUGIN_HH

#include "Object.hh"

namespace bemo {

class Plugin : public Object< Plugin > {
public:
    explicit Plugin( ObjectID id ) : Object< Plugin >( id ) {}
    void load() {}
    void unload() {}
};

}


#endif // BEMO_PLUGIN_HH
