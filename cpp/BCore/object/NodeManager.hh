#ifndef BEMO_NODEMANAGER_HH
#define BEMO_NODEMANAGER_HH

#include "Node.hh"

namespace bemo {

class NodeManager {
public:
    static NodeManager& instance();
public:
    NodeManager(NodeManager const&) = delete;
    void operator=(NodeManager const&) = delete;
public:
    BDagNode* create(const std::string& type, const std::string& name);
private:
    NodeManager() {}
    std::vector<BDagNode*> m_nodes;
};

}

#endif // BEMO_NODEMANAGER_HH
