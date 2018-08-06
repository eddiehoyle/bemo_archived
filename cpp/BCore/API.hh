#ifndef BEMO_API_HH
#define BEMO_API_HH

#include <string>

namespace bemo {

enum class ObjectType {
    Header,
    Node,
    Plug,

    /// Must be last
    Invalid,
};


enum class PlugDirection {
    Input,
    Output,
};

enum class PlugType {
    Int,
    String,
    Float,
    List,
    Dict,
    Variant,
};

class NodeRegistry;
class NodeManager;
class PlugManager;

extern NodeRegistry* BMO_NodeRegistry;
extern NodeManager* BMO_NodeManager;
extern PlugManager* BMO_PlugManager;

extern void send( const std::string& message );

extern void initialize();
extern void terminate();

}

#endif // BEMO_API_HH
