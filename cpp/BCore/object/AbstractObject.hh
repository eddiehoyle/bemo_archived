#ifndef BEMO_ABSTRACTMANAGEDOBJECT_HH
#define BEMO_ABSTRACTMANAGEDOBJECT_HH

#include <BCore/Platform.hh>
#include <BCore/managers/ObjectManager.hh>
#include <BCore/internal/Handle.hh>

namespace bemo {

using ObjectID = Handle< u32, 16, 16 >;

class ObjectManager;

class AbstractObject {
public:
    ObjectID objectID() const { return m_objectID; }
protected:
    explicit AbstractObject( ObjectID id ) : m_objectID( id ), m_manager( nullptr ) {}
    virtual ~AbstractObject() = default;
    bool operator==( const AbstractObject& rhs ) { return this->m_objectID == rhs.objectID(); }
protected:
    ObjectID m_objectID;
    ObjectManager* m_manager;
};

}

#endif // BEMO_ABSTRACTMANAGEDOBJECT_HH
