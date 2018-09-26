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

    BMO_EventHandler = new EventHandler();
    BMO_NodeManager = new NodeManager();
    BMO_PlugManager = new PlugManager();
    BMO_GraphManager = new GraphManager();
    BMO_PluginManager = new PluginManager();
    BMO_ObjectManager = new ObjectManager();
    BMO_ConnectionManager = new ConnectionManager();
    BMO_DependencyGraph = new DagManager();

    // Initialise CPP nodes
    BMO_NodeManager->addBlueprint( "multiply",
                                   new CreateFuncWrapper< std::function< AbstractNode*() > >( multiplyCreate ),
                                   new LayoutFuncWrapper< std::function< void(ObjectID) > >( multiplyLayout ) );
}

void terminate() {
    if ( BMO_EventHandler ) { delete BMO_EventHandler; }
    if ( BMO_NodeManager ) { delete BMO_NodeManager; }
    if ( BMO_PlugManager ) { delete BMO_PlugManager; }
    if ( BMO_GraphManager ) { delete BMO_GraphManager; }
    if ( BMO_PluginManager ) { delete BMO_PluginManager; }
    if ( BMO_ObjectManager ) { delete BMO_ObjectManager; }
    if ( BMO_ConnectionManager ) { delete BMO_ConnectionManager; }
    if ( BMO_DependencyGraph ) { delete BMO_DependencyGraph; }
}

void send( const std::string& message ) {}

} // namespace bemo
