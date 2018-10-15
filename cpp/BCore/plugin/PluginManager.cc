#include "PluginManager.hh"

namespace bemo {

PluginManager& PluginManager::instance() {
    static PluginManager mgr;
    return mgr;
}

}