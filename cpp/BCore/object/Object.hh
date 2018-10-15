#ifndef BEMO_ABSTRACTOBJECT_HH
#define BEMO_ABSTRACTOBJECT_HH

#include <string>
#include <vector>

#include "ObjectID.hh"

enum ObjectType {
    Null,
    Graph,
    Node,
    Plugin,
};

namespace bemo {

class Object {
public:
    Object() : m_objectID( ObjectID::invalid() ) {}
    virtual ~Object();
    bool isValid() const;
    ObjectID getObjectID() const { return m_objectID; }
    std::string getType() const { return m_type; }
    std::string getName() const { return m_name; }
protected:
    explicit Object( ObjectID id ) : m_objectID( id ) {}
private:
    ObjectID m_objectID;
    ObjectType m_objectType;
    std::string m_name;
    std::string m_type;
};

}
#endif // BEMO_ABSTRACTOBJECT_HH
