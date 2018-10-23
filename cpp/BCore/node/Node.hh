#ifndef BEMO_NODE_HH
#define BEMO_NODE_HH

#include "BCore/object/Object.hh"

namespace bemo {

class NodeManager;

class BDagNode {

    friend class NodeManager;

public:
    BDagNode();
    virtual ~BDagNode();

    virtual int execute() = 0;

    bool isValid() const;

    inline void setName( const std::string& name ) { m_name = name; }
    inline std::string getName() const { return m_name; }
    inline ObjectID getObjectID() const { return m_objectID; }
    inline std::string getType() const { return m_type; }

private:
    ObjectID m_objectID;
    std::string m_name;
    std::string m_type;
};

}

#endif // BEMO_NODE_HH
