#include "API.hh"
#include <BCore/util/Log.hh>
#include <BCore/managers/GraphManager.hh>
#include <BCore/managers/PlugManager.hh>

namespace bemo {

GraphManager* BMO_GraphManager = nullptr;
PlugManager* BMO_PlugManager = nullptr;

void initialize() {

    BMO_INITIALISE_LOG()

    if ( BMO_GraphManager == nullptr ) {
        BMO_GraphManager = new GraphManager();
    }

    if ( BMO_PlugManager == nullptr ) {
        BMO_PlugManager = new PlugManager();
    }
}

void terminate() {

    if ( BMO_GraphManager != nullptr ) {
        delete BMO_GraphManager;
        BMO_GraphManager = nullptr;
    }

    if ( BMO_PlugManager != nullptr ) {
        delete BMO_PlugManager;
        BMO_PlugManager = nullptr;
    }
}

} // namespace bemo
