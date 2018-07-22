#ifndef BEMO_API_HH
#define BEMO_API_HH

namespace bemo {

class GraphManager;
class PlugManager;
class NodeRegistry;

extern GraphManager* BMO_GraphManager;
extern PlugManager* BMO_PlugManager;
extern NodeRegistry* BMO_NodeRegistry;

extern void initialize();
extern void terminate();

}

#endif // BEMO_API_HH
