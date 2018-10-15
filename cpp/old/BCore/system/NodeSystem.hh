#ifndef BEMO_REGISTRYSYSTEM_HH
#define BEMO_REGISTRYSYSTEM_HH

#include <old/BCore/Bemo.hh>
#include <old/BCore/managers/PlugManager.hh>
#include <old/BCore/object/Plug.hh>
#include <old/BCore/object/AbstractNode.hh>

namespace bemo {

class NodeSystem {
public:
    explicit NodeSystem( const ObjectID& id ) : m_id( id ) {}

    void setHeader( const std::string& description,
                    const std::string& icon ) {}

    void addPlug( const std::string& name,
                  PlugDirectionPolicy direction,
                  PlugAccessPolicy access,
                  PlugCastPolicy cast,
                  VariantType type,
                  bool isRequired = false ) {
        ObjectID plugID = BMO_PlugManager->create( name,
                                                         direction,
                                                         access,
                                                         cast,
                                                         type,
                                                         isRequired );
        Plug* plug = BMO_PlugManager->find( plugID );
        plug->m_owner = m_id;
    }

private:
    ObjectID m_id;

};

}

#endif // BEMO_REGISTRYSYSTEM_HH
