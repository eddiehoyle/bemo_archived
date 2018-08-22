#ifndef BEMO_REGISTRYSYSTEM_HH
#define BEMO_REGISTRYSYSTEM_HH

#include <BCore/API.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractNode.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/managers/NodeManager.hh>

namespace bemo {

class NodeSystem {
public:
    explicit NodeSystem( const ObjectID& id ) : m_id( id ) {}

    void setHeader( const std::string& description,
                    const std::string& icon ) {}

    void addPlug( const std::string& name,
            PlugDirection direction,
            VariantType type,
            bool isRequired=false,
            bool isStrict=false ) {
        ObjectID plugID = BMO_PlugManager->create( name,
                                                   direction,
                                                   type,
                                                   isRequired,
                                                   isStrict );
        Plug* plug = BMO_PlugManager->find( plugID );
        plug->m_owner = m_id;
    }
private:
    ObjectID m_id;

};

}

#endif // BEMO_REGISTRYSYSTEM_HH
