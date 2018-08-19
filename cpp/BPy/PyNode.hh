#ifndef BEMO_PYABSTRACTNODE_HH
#define BEMO_PYABSTRACTNODE_HH

#include "PyNodeManager.hh"
#include <BCore/managers/NodeManager.hh>
#include <BCore/object/AbstractNode.hh>

#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace bemo {

class PyNode : public AbstractNode {
public:
    int execute() override {
        PYBIND11_OVERLOAD(
                int,
                AbstractNode,
                execute,
        );
    }
};

}

#endif // BEMO_PYABSTRACTNODE_HH
