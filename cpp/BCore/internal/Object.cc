#include "Object.hh"

namespace bemo {

std::ostream& operator<<( std::ostream& stream, const ObjectID& object ) {
    return stream << "ObjectID("
                  << "index=" << object.m_handle.index()
                  << ", version=" << object.m_handle.version()
                  << ")";
}

}