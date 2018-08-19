#ifndef BEMO_REGISTRYSYSTEM_HH
#define BEMO_REGISTRYSYSTEM_HH

#include <BCore/API.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractNode.hh>
#include <BCore/managers/PlugManager.hh>

namespace bemo {

class NodeSystem {
public:
    explicit NodeSystem( const ObjectID& id ) : m_id( id ) {}

    void setHeader( const std::string& name,
                    const std::string& description,
                    const std::string& icon ) {

    }
    void addPlug( const std::string& name,
            PlugDirection direction,
            PlugType type,
            bool isRequired=false,
            bool isStrict=false ) {
    }
private:
    ObjectID m_id;

};

}

#endif // BEMO_REGISTRYSYSTEM_HH
