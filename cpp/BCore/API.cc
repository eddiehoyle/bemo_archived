#include "API.hh"
#include <BCore/util/Log.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/NodeRegistry.hh>
#include <BCore/managers/PlugManager.hh>

namespace bemo {

PlugManager* BMO_PlugManager = nullptr;
NodeManager* BMO_NodeManager = nullptr;
NodeRegistry* BMO_NodeRegistry = nullptr;

void initialize() {

    BMO_INITIALISE_LOG()


    if ( BMO_NodeRegistry == nullptr ) {
        BMO_NodeRegistry = new NodeRegistry();
    }

    if ( BMO_NodeManager == nullptr ) {
        BMO_NodeManager = new NodeManager();
    }

    if ( BMO_PlugManager == nullptr ) {
        BMO_PlugManager = new PlugManager();
    }

}

void terminate() {

    if ( BMO_NodeRegistry != nullptr ) {
        delete BMO_NodeRegistry;
        BMO_NodeRegistry = nullptr;
    }

    if ( BMO_NodeManager != nullptr ) {
        delete BMO_NodeManager;
        BMO_NodeManager = nullptr;
    }

    if ( BMO_PlugManager != nullptr ) {
        delete BMO_PlugManager;
        BMO_PlugManager = nullptr;
    }

}

} // namespace bemo
