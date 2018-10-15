#include "Object.hh"

namespace bemo {

std::ostream& operator<<( std::ostream& stream, const ObjectID& object ) {
//    return stream << "ObjectID(" << object.m_handle.index() << ")";
    return stream << object.m_handle.value();
}

ObjectID ObjectID::invalid() {
    static ObjectID invalid;
    return invalid;
}

}