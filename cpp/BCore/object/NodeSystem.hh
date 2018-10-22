#ifndef BEMO_NODEREGISTRYSYSTEM_HH
#define BEMO_NODEREGISTRYSYSTEM_HH

#include <BCore/object/ObjectManager.hh>
#include <BCore/object/NodeRegistry.hh>
#include <BCore/object/NodeManager.hh>
#include <BCore/Assert.hh>
#include <string>

#include <BCore/Variant.hh>

namespace bemo {

enum class PlugDirectionPolicy {
    Input,
    Output,
    Ambiguous,
};

enum class PlugCastPolicy {
    Strict,
    Similar,
    Anything,
};

enum class PlugAccessPolicy {
    Single,
    Multiple,
};

class NodeSystem {
public:
    explicit NodeSystem( ObjectID id ) : m_id( id ) {}
    bool isValid() const { return ObjectManager::instance().exists(m_id); }

    void setHeader( const std::string& name,
                    const std::string& description,
                    const std::string& icon ) {}

    void setBlueprint( FnCreate fnCreate, FnLayout fnLayout ) {
        BDagNode* node = NodeManager::instance().find( m_id );
        BMO_ASSERT(node);
        NodeRegistry::instance().add( node->getType(), fnCreate, fnLayout );
    }

    void addPlug( const std::string& name,
                  PlugDirectionPolicy direction,
                  PlugAccessPolicy access,
                  PlugCastPolicy cast,
                  VariantType type,
                  bool isRequired = false ) {}
private:
    ObjectID m_id;

};

}

#endif // BEMO_NODEREGISTRYSYSTEM_HH
