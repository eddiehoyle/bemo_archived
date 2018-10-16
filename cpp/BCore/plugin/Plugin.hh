#ifndef BEMO_PLUGIN_HH
#define BEMO_PLUGIN_HH

#include <BCore/object/Object.hh>

namespace bemo {

class Plugin : public Object {
public:
    static constexpr ObjectType OBJECT_TYPE = { ObjectType::Plugin };
public:
    Plugin() : Object(), m_loaded( false ) {}
    explicit Plugin( ObjectID id ) : Object( id ) {}
    void load() { m_loaded = true; }
    void unload() { m_loaded = false; }
    bool isLoaded() const { return m_loaded; }
    void setPath( const std::string& path ) { m_path = path; }
private:
    bool m_loaded;
    std::string m_path;
};

}

#endif // BEMO_PLUGIN_HH
