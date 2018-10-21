#ifndef BEMO_PLUGIN_HH
#define BEMO_PLUGIN_HH

#include <BCore/object/Object.hh>
#include <BCore/object/ObjectManager.hh>

namespace bemo {

class PluginManager;

class Plugin : public Object {

    friend class PluginManager;

public:
    static constexpr ObjectType OBJECT_TYPE = { ObjectType::kPlugin };
public:
    void load() { m_loaded = true; }
    void unload() { m_loaded = false; }
    bool isLoaded() const { return m_loaded; }
    void setPath( const std::string& path ) { m_path = path; }
private:
    Plugin() : Object( ObjectManager::instance().acquire(), OBJECT_TYPE ), m_loaded( false ) {}
private:
    bool m_loaded;
    std::string m_path;
};

}

#endif // BEMO_PLUGIN_HH
