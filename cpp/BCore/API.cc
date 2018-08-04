#include "API.hh"
#include <BCore/util/Log.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/PlugManager.hh>

namespace bemo {

PlugManager* BMO_PlugManager = nullptr;
NodeManager* BMO_NodeManager = nullptr;

void initialize() {

    BMO_INITIALISE_LOG()

    if ( BMO_NodeManager == nullptr ) {
        BMO_NodeManager = new NodeManager();
    }

    if ( BMO_PlugManager == nullptr ) {
        BMO_PlugManager = new PlugManager();
    }

}

void terminate() {

    if ( BMO_NodeManager != nullptr ) {
        delete BMO_NodeManager;
        BMO_NodeManager = nullptr;
    }

    if ( BMO_PlugManager != nullptr ) {
        delete BMO_PlugManager;
        BMO_PlugManager = nullptr;
    }

}

void send( const std::string& message ) {

}

} // namespace bemo
