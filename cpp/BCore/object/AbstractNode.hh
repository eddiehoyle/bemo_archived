#ifndef BEMO_ABSTRACTNODE_HH
#define BEMO_ABSTRACTNODE_HH

#include <BCore/API.hh>
#include <BCore/Platform.hh>
#include <BCore/internal/Handle.hh>
#include <BCore/internal/Object.hh>

namespace bemo {

class Plug;

using NodeName = std::string;
using NodeType = std::string;

class AbstractNode {

    friend class NodeSystem;
    friend class NodeManager;

public:
    AbstractNode();
    virtual ~AbstractNode();

    inline bool isValid() const { return m_id != ObjectID(); }
    inline ObjectID getID() const { return m_id; }
    inline NodeType getType() const { return m_nodeType; }
    inline NodeName getName() const { return m_nodeName; }
    inline void setName( const NodeName& name ) { m_nodeName = name; }

    Plug* getPlug( const std::string& name );

    virtual int execute() { return -1; }

private:
    ObjectID m_id;
    NodeName m_nodeName;
    NodeType m_nodeType;
    std::vector< ObjectID > m_plugs;

};

}

#endif // BEMO_ABSTRACTNODE_HH
