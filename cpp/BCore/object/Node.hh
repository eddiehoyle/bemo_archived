#ifndef BEMO_NODE_HH
#define BEMO_NODE_HH

#include "Object.hh"

namespace bemo {

class NodeManager;

class BDagNode {

    friend class NodeManager;

public:
    BDagNode();
    virtual ~BDagNode();

    bool isValid() const;

    virtual int execute() = 0;

    void setName( const std::string& name ) { m_name = name; }

    ObjectID getObjectID() const { return m_objectID; }
    ObjectType getObjectType() const { return m_objectType; }
    std::string getType() const { return m_type; }
    std::string getName() const { return m_name; }

private:
    ObjectID m_objectID;
    ObjectType m_objectType;
    std::string m_name;
    std::string m_type;
};

}
#endif // BEMO_NODE_HH
