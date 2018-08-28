//
// Created by Eddie Hoyle on 8/07/18.
//

#ifndef BEMO_BEMO_HH
#define BEMO_BEMO_HH

#include "API.hh"

namespace bemo {

class NodeManager;
class PlugManager;
class GraphManager;
class PluginManager;
class ObjectManager;
class ConnectionManager;

using NodeManagerPtr = std::shared_ptr< NodeManager >;
using PlugManagerPtr = std::shared_ptr< PlugManager >;
using GraphManagerPtr = std::shared_ptr< GraphManager >;
using PluginManagerPtr = std::shared_ptr< PluginManager >;
using ObjectManagerPtr = std::shared_ptr< ObjectManager >;
using ConnectionManagerPtr = std::shared_ptr< ConnectionManager >;

class BemoEngine {
public:
    BemoEngine();
    ~BemoEngine();
    NodeManagerPtr getNodeManager();
    PlugManagerPtr getPlugManager();
    GraphManagerPtr getGraphManager();
    PluginManagerPtr getPluginManager();
    ObjectManagerPtr getObjectManager();
    ConnectionManagerPtr getConnectionManager();

private:
    NodeManagerPtr m_nodeManager;
    PlugManagerPtr m_plugManager;
    GraphManagerPtr m_graphManager;
    PluginManagerPtr m_pluginManager;
    ObjectManagerPtr m_objectManager;
    ConnectionManagerPtr m_connectionManager;
};

}

#endif // BEMO_BEMO_HH
