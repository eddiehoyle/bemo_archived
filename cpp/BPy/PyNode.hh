#ifndef BEMO_PYNODE_HH
#define BEMO_PYNODE_HH

#include <BCore/Assert.hh>
#include <BCore/node/Node.hh>
#include <BCore/object/ObjectID.hh>
#include <BCore/object/ObjectManager.hh>
#include <BCore/plugin/PluginSystem.hh>

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>


class BPyOpenNode : public bemo::BDagNode {
public:
    BPyOpenNode();
    ~BPyOpenNode() override;
    int execute() override;
};

class BPyOpenObject : public bemo::Object {
public:
    ~BPyOpenObject() override = default;
};

class BPyNode {
public:
    static std::shared_ptr<BPyNode> create( const std::string& type, const std::string& name );
    explicit BPyNode( bemo::ObjectID id );
    ~BPyNode();
    bool isValid() const;
    bemo::ObjectID getObjectID() const { return m_id; }
    bool operator==( const BPyNode* node) const {
        return node->getObjectID() == m_id;
    }
private:
    bemo::ObjectID m_id;
};

//typedef std::function<bemo::BDagNode*()> PyFnCreate;
typedef std::function<pybind11::object()> PyFnCreate;

//typedef std::function< bemo::Object*() > CreateFunctor;
//typedef std::function< void( bemo::ObjectID ) > LayoutFunctor;

#endif // BEMO_PYNODE_HH
