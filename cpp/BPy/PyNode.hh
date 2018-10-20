#ifndef BEMO_PYNODE_HH
#define BEMO_PYNODE_HH

#include <BCore/Assert.hh>
#include <BCore/object/Node.hh>
#include <BCore/object/ObjectID.hh>
#include <BCore/object/ObjectManager.hh>
#include <BCore/plugin/PluginSystem.hh>

class BPyOpenNode : public bemo::BDagNode {
public:
    BPyOpenNode();
    ~BPyOpenNode() override;
    int execute() override;
};

class BPyNode {
public:
    explicit BPyNode( bemo::ObjectID id );
    ~BPyNode();
    bool isValid() const;
private:
    bemo::ObjectID m_id;
};

#endif // BEMO_PYNODE_HH
