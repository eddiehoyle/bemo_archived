#ifndef BEMO_ABSTRACTMANAGEDOBJECT_HH
#define BEMO_ABSTRACTMANAGEDOBJECT_HH

#include <BCore/Platform.hh>

namespace bemo {

class ObjectManager;

class AbstractManagedObject {

    friend class ObjectManager;

public:
    ObjectID objectID() const { return m_objectID; }
protected:
    explicit AbstractManagedObject( ObjectID id ) : m_objectID( id ), m_manager( nullptr ) {}
    virtual ~AbstractManagedObject() = default;
protected:
    ObjectID m_objectID;
    ObjectManager* m_manager;
};

}

#endif // BEMO_ABSTRACTMANAGEDOBJECT_HH
