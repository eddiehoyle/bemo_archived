#ifndef BEMO_TYPE_HH
#define BEMO_TYPE_HH

namespace bemo {

enum class ObjectType {

    /// Objects
    Graph,
    Node,
    Plug,
    Plugin,

    /// Data
    Data,
    DataArray,

    /// Must be last
    Invalid,
};

}
#endif // BEMO_TYPE_HH
