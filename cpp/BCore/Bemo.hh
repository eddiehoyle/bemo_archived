#ifndef BEMO_API_HH
#define BEMO_API_HH

namespace bemo {

class NodeManager;
class PlugManager;
class GraphManager;
class PluginManager;
class ObjectManager;
class ConnectionManager;
class EventHandler;
class DagManager;

extern NodeManager* BMO_NodeManager;
extern PlugManager* BMO_PlugManager;
extern GraphManager* BMO_GraphManager;
extern PluginManager* BMO_PluginManager;
extern ObjectManager* BMO_ObjectManager;
extern ConnectionManager* BMO_ConnectionManager;
extern EventHandler* BMO_EventHandler;
extern DagManager* BMO_DependencyGraph;

extern void initialize();
extern void terminate();

}

#endif // BEMO_API_HH
