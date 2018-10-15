#include "ObjectID.hh"

namespace bemo {

std::ostream& operator<<( std::ostream& stream, const ObjectID& object ) {
    return stream << object.m_handle.value();
}

ObjectID ObjectID::invalid() {
    static ObjectID invalid;
    return invalid;
}

}