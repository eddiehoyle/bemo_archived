#ifndef BEMO_MULTIPLYNODE_HH
#define BEMO_MULTIPLYNODE_HH

#include <BCore/node/Node.hh>
#include <BCore/plugin/PluginManager.hh>
#include <BCore/plugin/PluginSystem.hh>
#include <BCore/node/NodeSystem.hh>

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace bemo {

class MultiplyNode : public BDagNode {
public:
    MultiplyNode();
    ~MultiplyNode() override;
    int execute() override;
};

pybind11::object multiplyCreate();

void multiplyLayout( ObjectID nodeID );

}

#endif // BEMO_SUM_HH
