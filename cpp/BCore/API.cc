#include "API.hh"
#include <BCore/util/Log.hh>
#include <BCore/managers/GraphManager.hh>
#include <BCore/managers/ObjectManager.hh>

namespace bemo {

GraphManager* BMO_GraphManager = nullptr;
ObjectManager* BMO_ObjectManager = nullptr;

void initialize() {

    BMO_INITIALISE_LOG()

    if ( BMO_GraphManager == nullptr ) {
        BMO_GraphManager = new GraphManager();
    }

    if ( BMO_ObjectManager == nullptr ) {
        BMO_ObjectManager = new ObjectManager();
    }
}

void terminate() {

    if ( BMO_GraphManager != nullptr ) {
        delete BMO_GraphManager;
        BMO_GraphManager = nullptr;
    }

    if ( BMO_ObjectManager != nullptr ) {
        delete BMO_ObjectManager;
        BMO_ObjectManager = nullptr;
    }
}

} // namespace bemo
