#include "PluginManager.hh"
#include "PluginSystem.hh"
#include <BCore/node/MultiplyNode.hh>

#include <functional>

namespace bemo {

PluginManager& PluginManager::instance() {
    static PluginManager mgr;
    return mgr;
}

PluginManager::PluginManager() {
    // TODO: Remove this
//    AbstractCreateFuncWrapper* wrap = new CreateNodeFuncWrapper< std::function< Object*() > >( &multiplyCreate );
//    addWrapper( ObjectID::invalid(), "multiply", wrap );
}

}