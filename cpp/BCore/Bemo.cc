#include "Bemo.hh"

#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/managers/GraphManager.hh>
#include <BCore/managers/PluginManager.hh>
#include <BCore/managers/ObjectManager.hh>
#include <BCore/managers/ConnectionManager.hh>

namespace bemo {
BemoEngine::BemoEngine()
        : m_nodeManager( new NodeManager() ),
          m_plugManager( new PlugManager() ),
          m_graphManager( nullptr ),
          m_pluginManager( new PluginManager() ),
          m_objectManager( new ObjectManager() ),
          m_connectionManager( new ConnectionManager() ) {
}

BemoEngine::~BemoEngine() {}

NodeManagerPtr BemoEngine::getNodeManager() {
    return m_nodeManager;
}

PlugManagerPtr BemoEngine::getPlugManager() {
    return m_plugManager;
}

GraphManagerPtr BemoEngine::getGraphManager() {
    return m_graphManager;
}

PluginManagerPtr BemoEngine::getPluginManager() {
    return m_pluginManager;
}

ObjectManagerPtr BemoEngine::getObjectManager() {
    return m_objectManager;
}

ConnectionManagerPtr BemoEngine::getConnectionManager() {
    return m_connectionManager;
}

}