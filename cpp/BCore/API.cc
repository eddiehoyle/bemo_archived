#include <BCore/util/Log.hh>
#include "API.hh"
#include <BCore/managers/ContainerManager.hh>
#include <BCore/managers/ObjectManager.hh>

namespace bemo {

ContainerManager* BMO_ContainerManager = nullptr;
ObjectManager* BMO_ObjectManager = nullptr;

void initialize() {

    BMO_INITIALISE_LOG()

    if ( BMO_ContainerManager == nullptr ) {
        BMO_ContainerManager = new ContainerManager();
    }

    if ( BMO_ObjectManager == nullptr ) {
        BMO_ObjectManager = new ObjectManager();
    }
}

void terminate() {

    if ( BMO_ContainerManager != nullptr ) {
        delete BMO_ContainerManager;
        BMO_ContainerManager = nullptr;
    }

    if ( BMO_ObjectManager != nullptr ) {
        delete BMO_ObjectManager;
        BMO_ObjectManager = nullptr;
    }
}

} // namespace bemo
