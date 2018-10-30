#include "NodeRegistry.hh"

namespace bemo {

NodeRegistry& NodeRegistry::instance() {
    static NodeRegistry mgr;
    return mgr;
}

NodeRegistry::NodeRegistry() {

}

}