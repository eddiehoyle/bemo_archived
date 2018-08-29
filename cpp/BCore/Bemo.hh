#ifndef BEMO_API_HH
#define BEMO_API_HH

namespace bemo {

class NodeManager;
class PlugManager;
class GraphManager;
class PluginManager;
class ObjectManager;
class ConnectionManager;

class BemoEngine {
public:
    BemoEngine();
    ~BemoEngine();

    NodeManager* getNodeManager();
    PlugManager* getPlugManager();
    GraphManager* getGraphManager();
    PluginManager* getPluginManager();
    ObjectManager* getObjectManager();
    ConnectionManager* getConnectionManager();

private:
    NodeManager* m_nodeManager;
    PlugManager* m_plugManager;
    GraphManager* m_graphManager;
    PluginManager* m_pluginManager;
    ObjectManager* m_objectManager;
    ConnectionManager* m_connectionManager;
};

extern void initialize();
extern void terminate();
extern BemoEngine* BMO;

}

#endif // BEMO_API_HH
