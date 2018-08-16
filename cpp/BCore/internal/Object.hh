#ifndef BEMO_OBJECT_HH
#define BEMO_OBJECT_HH

#include "Handle.hh"
#include <BCore/Platform.hh>

namespace bemo {

using ObjectID = Handle< u32, 16, 16 >;

class BObject {

    friend class ObjectManager;

public:
    BObject() : m_handle( ObjectID::INVALID_HANDLE ),
                m_type( ObjectType::Invalid ),
                m_typeStr() {}
    ObjectType type() const { return m_type; }
    std::string typeStr() const { return m_typeStr; }
private:
    ObjectID m_handle;
    ObjectType m_type;
    std::string m_typeStr;
};

}

#endif // BEMO_OBJECT_HH
