#ifndef BEMO_REGISTRYSYSTEM_HH
#define BEMO_REGISTRYSYSTEM_HH

#include <BCore/API.hh>
#include <BCore/object/Plug.hh>
#include <BCore/object/AbstractNode.hh>

namespace bemo {

class NodeSystem {
public:
    explicit NodeSystem( const NodeID& id ) : m_nodeID( id ) {}

    void setHeader( const std::string& name,
                    const std::string& description,
                    const std::string& icon ) {
        BMO_ERROR << "Adding header=" << name << ", to nodeID=" << m_nodeID;

    }
    void addPlug( const std::string& name,
            PlugDirection direction,
            PlugType type,
            bool isRequired=false,
            bool isStrict=false ) {
        BMO_ERROR << "Adding plug=" << name << ", to nodeID=" << m_nodeID;
    }
private:
    NodeID m_nodeID;

};

}

#endif // BEMO_REGISTRYSYSTEM_HH
