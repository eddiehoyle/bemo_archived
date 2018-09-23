#ifndef BEMO_ABSTRACTNODE_HH
#define BEMO_ABSTRACTNODE_HH

#include <BCore/Bemo.hh>
#include <BCore/Platform.hh>
#include <BCore/internal/Handle.hh>
#include <BCore/internal/Object.hh>
#include <BCore/object/Plug.hh>
#include <BCore/Variant.hh>

namespace bemo {

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
    void setName( const NodeName& name );

    virtual int execute();

protected:
    ObjectID m_id;

private:
    NodeName m_nodeName;
    NodeType m_nodeType;
    std::vector< ObjectID > m_plugs;

};

}

#endif // BEMO_ABSTRACTNODE_HH
