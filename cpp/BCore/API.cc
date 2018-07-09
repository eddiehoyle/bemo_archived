#include <BCore/util/Log.hh>
#include "API.hh"
#include <BCore/managers/ContainerManager.hh>

namespace bemo {

ContainerManager* BMO_ContainerManager = nullptr;

void initialize() {
    BMO_ERROR << "starting up";
    if ( BMO_ContainerManager == nullptr ) {
        BMO_ContainerManager = new ContainerManager();
    }
}

void terminate() {
    BMO_ERROR << "shutting down";
    if ( BMO_ContainerManager != nullptr ) {
        delete BMO_ContainerManager;
        BMO_ContainerManager = nullptr;
    }
}

} // namespace bemo
