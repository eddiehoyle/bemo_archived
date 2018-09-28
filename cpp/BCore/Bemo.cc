#include "Bemo.hh"

#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/managers/GraphManager.hh>
#include <BCore/managers/PluginManager.hh>
#include <BCore/managers/ObjectManager.hh>
#include <BCore/managers/ConnectionManager.hh>

#include <BCore/system/PluginSystem.hh>
#include <BCore/system/NodeSystem.hh>
#include <BCore/event/EventHandler.hh>

#include <BCore/dag/DagManager.hh>

#include <BCore/util/Log.hh>
#include <BCore/node/MultiplyNode.hh>

namespace bemo {

NodeManager* BMO_NodeManager = nullptr;
PlugManager* BMO_PlugManager = nullptr;
GraphManager* BMO_GraphManager = nullptr;
PluginManager* BMO_PluginManager = nullptr;
ObjectManager* BMO_ObjectManager = nullptr;
ConnectionManager* BMO_ConnectionManager = nullptr;
EventHandler* BMO_EventHandler = nullptr;
DagManager* BMO_DependencyGraph = nullptr;

void initialize() {

    BMO_INITIALISE_LOG()

    if ( BMO_EventHandler == nullptr ) {
        BMO_EventHandler = new EventHandler();
    }
    if ( BMO_ObjectManager == nullptr ) {
        BMO_ObjectManager = new ObjectManager();
    }
    if ( BMO_NodeManager == nullptr ) {
        BMO_NodeManager = new NodeManager();

        // Initialise CPP nodes
        BMO_NodeManager->addBlueprint( "multiply",
                                       new CreateFuncWrapper< std::function< AbstractNode*() > >( multiplyCreate ),
                                       new LayoutFuncWrapper< std::function< void(ObjectID) > >( multiplyLayout ) );
    }
    if ( BMO_PlugManager == nullptr ) {
        BMO_PlugManager = new PlugManager();
    }
    if ( BMO_GraphManager == nullptr ) {
        BMO_GraphManager = new GraphManager();
    }
    if ( BMO_PluginManager == nullptr ) {
        BMO_PluginManager = new PluginManager();
    }
    if ( BMO_ConnectionManager == nullptr ) {
        BMO_ConnectionManager = new ConnectionManager();
    }
    if ( BMO_DependencyGraph == nullptr ) {
        BMO_DependencyGraph = new DagManager();
    }
}

void terminate() {
    if ( BMO_EventHandler ) {
        delete BMO_EventHandler;
        BMO_EventHandler = nullptr;
    }
    if ( BMO_NodeManager ) {
        delete BMO_NodeManager;
        BMO_NodeManager = nullptr;
    }
    if ( BMO_PlugManager ) {
        delete BMO_PlugManager;
        BMO_PlugManager = nullptr;
    }
    if ( BMO_GraphManager ) {
        delete BMO_GraphManager;
        BMO_GraphManager = nullptr;
    }
    if ( BMO_PluginManager ) {
        delete BMO_PluginManager;
        BMO_PluginManager = nullptr;
    }
    if ( BMO_ObjectManager ) {
        delete BMO_ObjectManager;
        BMO_ObjectManager = nullptr;
    }
    if ( BMO_ConnectionManager ) {
        delete BMO_ConnectionManager;
        BMO_ConnectionManager = nullptr;
    }
    if ( BMO_DependencyGraph ) {
        delete BMO_DependencyGraph;
        BMO_DependencyGraph = nullptr;
    }
}

void send( const std::string& message ) {}

} // namespace bemo
