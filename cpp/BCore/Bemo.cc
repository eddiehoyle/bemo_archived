#include "Bemo.hh"

#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/managers/GraphManager.hh>
#include <BCore/managers/PluginManager.hh>
#include <BCore/managers/ObjectManager.hh>
#include <BCore/managers/ConnectionManager.hh>

#include <BCore/system/PluginSystem.hh>
#include <BCore/system/NodeSystem.hh>

#include <BCore/util/Log.hh>
#include <BCore/node/Sum.hh>

namespace bemo {

BemoEngine* BMO = nullptr;

BemoEngine::BemoEngine()
        : m_nodeManager( new NodeManager() ),
          m_plugManager( new PlugManager() ),
          m_graphManager( nullptr ),
          m_pluginManager( new PluginManager() ),
          m_objectManager( new ObjectManager() ),
          m_connectionManager( new ConnectionManager() ) {}

BemoEngine::~BemoEngine() {}

NodeManager* BemoEngine::getNodeManager() {
    return m_nodeManager;
}

PlugManager* BemoEngine::getPlugManager() {
    return m_plugManager;
}

GraphManager* BemoEngine::getGraphManager() {
    return m_graphManager;
}

PluginManager* BemoEngine::getPluginManager() {
    return m_pluginManager;
}

ObjectManager* BemoEngine::getObjectManager() {
    return m_objectManager;
}

ConnectionManager* BemoEngine::getConnectionManager() {
    return m_connectionManager;
}


void initialize() {

    BMO_INITIALISE_LOG()

    if ( BMO == nullptr ) {
        BMO = new BemoEngine();
    }

    // Initialise CPP nodes
    BMO->getNodeManager()->addBlueprint( "cpp",
                                         new CreateFuncWrapper< CppFnCreate >( a ),
                                         new LayoutFuncWrapper< CppFnLayout >( b ) );
}

void terminate() {

    if ( BMO != nullptr ) {
        delete BMO;
        BMO = nullptr;
    }

}

void send( const std::string& message ) {}

} // namespace bemo
