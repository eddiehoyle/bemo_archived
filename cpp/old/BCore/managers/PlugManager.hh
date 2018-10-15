#ifndef BEMO_PLUGMANAGER_HH
#define BEMO_PLUGMANAGER_HH

#include <old/BCore/Bemo.hh>
#include <old/BCore/managers/ObjectManager.hh>
#include <old/BCore/object/Plug.hh>
#include <old/BCore/internal/Object.hh>

namespace bemo {

class PlugManager {

public:

    ObjectID create( const std::string& name,
                     PlugDirectionPolicy direction,
                     PlugAccessPolicy access,
                     PlugCastPolicy cast,
                     VariantType type,
                     bool isRequired = false,
                     bool isStrict = false ) {
        ObjectID id = BMO_ObjectManager->acquire( ObjectType::Plug );
        Plug * plug = new Plug( name, direction, access, cast, type );
        plug->m_id = id;
        plug->setRequired( isRequired );
        m_plugs.push_back( plug );
        return id;
    }

    ObjectID getOwner( ObjectID plugID ) const {
        auto iter = std::find_if( m_plugs.begin(),
                                  m_plugs.end(),
                                  [&]( Plug* plug ) {
                                      return plug->getID() == plugID;
                                  } );
        return iter != m_plugs.end() ? ( *iter )->getOwnerID()
                                     : ObjectID::invalid();
    }

    std::vector< PlugName > getOwnerPlugNames( const ObjectID& owner,
                                               PlugDirectionPolicy direction ) {
        std::vector< PlugName > names;
        for ( Plug* plug : m_plugs ) {
            if ( plug->getOwnerID() == owner &&
                 plug->getDirection() == direction ) {
                names.push_back( plug->getName() );
            }
        }
        return names;
    }

    Plug* find( const ObjectID& owner,
                const PlugName& name,
                PlugDirectionPolicy direction ) const {
        auto iter = std::find_if( m_plugs.begin(),
                                  m_plugs.end(),
                                  [&]( Plug* plug ) {
                                      return ( plug->getOwnerID() ==
                                               owner ) &&
                                             ( plug->getDirection() ==
                                               direction ) &&
                                             ( plug->m_name == name );
                                  } );
        return iter != m_plugs.end() ? *iter : nullptr;
    }

    Plug* find( const ObjectID& id ) const {
        auto iter = std::find_if( m_plugs.begin(),
                                  m_plugs.end(),
                                  [id]( Plug* plug ) {
                                      return plug->m_id == id;
                                  } );
        return iter != m_plugs.end() ? *iter : nullptr;
    }

private:
    std::vector< Plug* > m_plugs;
};


}

#endif // BEMO_PLUGMANAGER_HH
