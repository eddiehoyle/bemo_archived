#ifndef BEMO_PLUGMANAGER_HH
#define BEMO_PLUGMANAGER_HH

#include "ObjectManager.hh"
#include <BCore/object/Plug.hh>
#include <BCore/internal/Object.hh>

namespace bemo {

class PlugManager {

public:

    ObjectID create( const std::string& name,
                     PlugDirection direction,
                     PlugType type,
                     bool isRequired=false,
                     bool isStrict=false ) {
        ObjectID id = BMO_ObjectManager->acquire( ObjectType::Plug );
        Plug* plug = new Plug( name, direction, type );
        plug->m_id = id;
        plug->setRequired( isRequired );
        plug->setStrict( isStrict );
        m_plugs.push_back( plug );
        return id;
    }

    Plug* find( const std::string& name ) const {
        auto iter = std::find_if( m_plugs.begin(),
                                  m_plugs.end(),
                                  [&]( Plug* plugin ) {
                                      return plugin->m_name == name;
                                  });
        return iter != m_plugs.end() ? *iter : nullptr;
    }

    Plug* find( const ObjectID& id ) const {
        auto iter = std::find_if( m_plugs.begin(),
                                  m_plugs.end(),
                                  [id]( Plug* plugin ) {
                                      return plugin->m_id == id;
                                  });
        return iter != m_plugs.end() ? *iter : nullptr;
    }

private:
    std::vector< Plug* > m_plugs;
};


}

#endif // BEMO_PLUGMANAGER_HH
