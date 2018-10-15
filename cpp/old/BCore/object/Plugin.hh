#ifndef BEMO_PLUGIN_HH
#define BEMO_PLUGIN_HH

#include <old/BCore/internal/Object.hh>

namespace bemo {

class Plugin {

    friend class PluginManager;

public:
    Plugin() : m_id(),
               m_loaded( false ) {}
    void load() { m_loaded = true; }
    void unload() { m_loaded = false; }
    bool isLoaded() const { return m_loaded; }
private:
    ObjectID m_id;
    bool m_loaded;
};

}


#endif // BEMO_PLUGIN_HH
