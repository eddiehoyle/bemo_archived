#ifndef BEMO_ABSTRACTOBJECT_HH
#define BEMO_ABSTRACTOBJECT_HH

#include <string>
#include <vector>

#include "ObjectID.hh"

namespace bemo {

enum ObjectType {
    kNull,
    kGraph,
    kNode,
    kPlugin,
};

//class Object;
//typedef std::function< Object*() > CreateFunctor;
//typedef std::function< void( ObjectID ) > LayoutFunctor;

class Object {
public:
    Object() : m_objectID( ObjectID::invalid() ), m_objectType( kNull ) {}
    explicit Object( ObjectType type ) : m_objectID( ObjectID::invalid() ), m_objectType( type ) {}
    virtual ~Object();

    bool isValid() const;

    ObjectID getObjectID() const { return m_objectID; }
    ObjectType getObjectType() const { return m_objectType; }
    std::string getType() const { return m_type; }
    std::string getName() const { return m_name; }

    void setName( const std::string& name ) { m_name = name; }
protected:
    explicit Object( ObjectID id, ObjectType type ) : m_objectID( id ), m_objectType( type ) {}
private:
    ObjectID m_objectID;
    ObjectType m_objectType;
    std::string m_name;
    std::string m_type;
};

}
#endif // BEMO_ABSTRACTOBJECT_HH
