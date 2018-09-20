#ifndef BEMO_PYABSTRACTNODE_HH
#define BEMO_PYABSTRACTNODE_HH

#include <BCore/managers/NodeManager.hh>
#include <BCore/object/AbstractNode.hh>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

using namespace bemo;

class PyAbstractNode : public AbstractNode {
public:
    using AbstractNode::AbstractNode;

    int execute() override {
        PYBIND11_OVERLOAD(
                int,
                AbstractNode,
                execute,
        );
    }
};

#endif // BEMO_PYABSTRACTNODE_HH
