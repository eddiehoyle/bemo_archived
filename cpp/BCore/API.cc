#include "API.hh"
#include <BCore/util/Log.hh>
#include <BCore/managers/GraphManager.hh>
#include <BCore/managers/PlugManager.hh>

namespace bemo {

GraphManager* BMO_GraphManager = nullptr;
PlugManager* BMO_PlugManager = nullptr;
NodeRegistry* BMO_NodeRegistry = nullptr;

void initialize() {

    BMO_INITIALISE_LOG()

    if ( BMO_GraphManager == nullptr ) {
        BMO_GraphManager = new GraphManager();
    }

    if ( BMO_PlugManager == nullptr ) {
        BMO_PlugManager = new PlugManager();
    }

    if ( BMO_NodeRegistry == nullptr ) {
        BMO_NodeRegistry = new NodeRegistry();

        // Add simple node
        BMO_NodeRegistry->add( AddNode::nodeTypeID(),
                               AddNode::create,
                               AddHeader::header,
                               AddLayout::layout );
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
