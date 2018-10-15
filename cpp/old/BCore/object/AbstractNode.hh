#ifndef BEMO_ABSTRACTNODE_HH
#define BEMO_ABSTRACTNODE_HH

#include <old/BCore/Bemo.hh>
#include <old/BCore/Platform.hh>
#include <old/BCore/internal/Handle.hh>
#include <old/BCore/internal/Object.hh>
#include <old/BCore/object/Plug.hh>
#include <old/BCore/Variant.hh>

namespace bemo {

typedef std::string NodeName;
typedef std::string NodeType;

class AbstractNode {

    friend class NodeSystem;
    friend class NodeManager;

public:
    AbstractNode();
    virtual ~AbstractNode();

    inline bool isValid() const { return m_id != ObjectID(); }
    inline ObjectID getID() const { return m_id; }
    inline NodeType getType() const { return m_nodeType; }
    inline NodeName getName() const { return m_objectName; }
    inline NodeManager* getManager() const;
    void setName( const NodeName& name );

    virtual int execute();

protected:
    ObjectID m_id;

private:
    NodeName m_objectName;
    NodeType m_nodeType;
    NodeManager* m_manager;
};

}

#endif // BEMO_ABSTRACTNODE_HH
