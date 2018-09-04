#include "Object.hh"

namespace bemo {

std::ostream& operator<<( std::ostream& stream, const ObjectID& object ) {
    return stream << "ObjectID(" << object.m_handle.index() << ")";
}

ObjectID ObjectID::invalid() {
    static ObjectID invalid;
    return invalid;
}

}