#ifndef BEMO_NODEMANAGER_HH
#define BEMO_NODEMANAGER_HH

#include <vector>

#include "Node.hh"

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace bemo {

class NodeManager {
public:
    static NodeManager& instance();
public:
    NodeManager(NodeManager const&) = delete;
    void operator=(NodeManager const&) = delete;
public:
    ObjectID create(const std::string& type, const std::string& name);
    BDagNode* find(ObjectID id) const;
    std::vector<BDagNode*> list() const;
private:
    NodeManager() {}
    std::vector<BDagNode*> m_nodes;
};

}

#endif // BEMO_NODEMANAGER_HH
