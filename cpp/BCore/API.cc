#include <BCore/util/Log.hh>
#include "API.hh"
#include "Graph.hh"

namespace bemo {

GraphManager* BMO_GraphManager = nullptr;

void initialize() {
    BMO_ERROR << "starting up";
    if ( BMO_GraphManager == nullptr ) {
        BMO_GraphManager = new GraphManager();

    }
}

void terminate() {
    BMO_ERROR << "shutting down";
    if ( BMO_GraphManager != nullptr ) {
        delete BMO_GraphManager;
        BMO_GraphManager = nullptr;
    }
}

} // namespace bemo
