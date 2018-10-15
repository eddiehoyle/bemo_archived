#ifndef BEMO_OBJECTID_HH
#define BEMO_OBJECTID_HH

#include <ostream>

#include "Handle.hh"
#include <BCore/Platform.hh>

namespace bemo {

using ObjectHandle = Handle< u64, 32, 32 >;

class ObjectManager;

class ObjectID {

    friend class ObjectManager;

public:
    static ObjectID invalid();

public:
    explicit ObjectID( ObjectHandle handle ) : m_handle( handle ) {}
    ObjectID() : m_handle( ObjectHandle::INVALID_HANDLE ) {}
    ObjectID( const ObjectID& obj ) : m_handle( obj.m_handle ) {}
    ObjectID& operator=( const ObjectID& obj ) {
        this->m_handle = obj.m_handle;
        return *this;
    }
    bool operator<( const ObjectID& rhs ) const { return this->m_handle < rhs.m_handle; }
    bool operator>( const ObjectID& rhs ) const { return this->m_handle > rhs.m_handle; }
    bool operator==( const ObjectID& rhs ) const { return this->m_handle == rhs.m_handle; }
    bool operator!=( const ObjectID& rhs ) const { return this->m_handle != rhs.m_handle; }

    friend std::ostream& operator<<( std::ostream& stream, const ObjectID& object );

private:
    ObjectHandle m_handle;
};

}

#endif // BEMO_OBJECTID_HH
