#ifndef BEMO_API_HH
#define BEMO_API_HH

#include <string>

namespace bemo {

enum class ObjectType {

    /// Objects
    Node,
    Plug,
    Plugin,

    /// Data
    Data,
    DataArray,

    /// Must be last
    Invalid,
};

class NodeManager;
class PlugManager;
class PluginManager;
class ObjectManager;
class DataBlockManager;
class ConnectionManager;

extern NodeManager* BMO_NodeManager;
extern PlugManager* BMO_PlugManager;
extern PluginManager* BMO_PluginManager;
extern ObjectManager* BMO_ObjectManager;
extern DataBlockManager* BMO_DataBlockManager;
extern ConnectionManager* BMO_ConnectionManager;

extern void send( const std::string& message );

extern void initialize();
extern void terminate();

}

#endif // BEMO_API_HH
