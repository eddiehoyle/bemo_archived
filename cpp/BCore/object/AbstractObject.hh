#ifndef BEMO_ABSTRACTMANAGEDOBJECT_HH
#define BEMO_ABSTRACTMANAGEDOBJECT_HH

#include <BCore/Platform.hh>
#include <BCore/managers/ObjectManager.hh>
#include <BCore/internal/Handle.hh>

namespace bemo {

using ObjectID = Handle< u32, 16, 16 >;

class ObjectManager;

template< typename T, typename H >
class AbstractObject {
public:
    using ObjectType = T;
    using HandleType = H;
public:
    HandleType objectID() const { return m_objectID; }
protected:
    explicit AbstractObject( HandleType id ) : m_objectID( id ), m_manager( nullptr ) {}
    virtual ~AbstractObject() = default;
protected:
    HandleType m_objectID;
    ObjectManager* m_manager;
};

}

#endif // BEMO_ABSTRACTMANAGEDOBJECT_HH
