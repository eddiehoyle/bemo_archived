#include "NodeManager.hh"

namespace bemo {

NodeManager& NodeManager::instance() {
    static NodeManager mgr;
    return mgr;
}

BDagNode* NodeManager::create( const std::string& type,
                               const std::string& name ) {
    return nullptr;
}

}