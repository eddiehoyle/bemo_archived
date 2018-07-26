#ifndef BEMO_PLUGIN_HH
#define BEMO_PLUGIN_HH

#include "Object.hh"

namespace bemo {

class Plugin : public Object< Plugin > {
public:
    void load() {}
    void unload() {}
private:
    ObjectID m_headerID;
};

}


#endif // BEMO_PLUGIN_HH
