#ifndef BEMO_REGISTRYSYSTEM_HH
#define BEMO_REGISTRYSYSTEM_HH

#include <BCore/Bemo.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractNode.hh>

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
        ObjectID plugID = BMO->getPlugManager()->create( name,
                                                         direction,
                                                         access,
                                                         cast,
                                                         type,
                                                         isRequired );
        Plug* plug = BMO->getPlugManager()->find( plugID );
        plug->m_owner = m_id;
    }

private:
    ObjectID m_id;

};

}

#endif // BEMO_REGISTRYSYSTEM_HH
