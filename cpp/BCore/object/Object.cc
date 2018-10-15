#include "Object.hh"
#include "ObjectManager.hh"

namespace bemo {

Object::~Object() {
    BMO_ERROR << "about to release id=" << getObjectID();
    ObjectManager::instance().release( getObjectID() );
}

bool Object::isValid() const {
    return ObjectManager::instance().exists( getObjectID() );
}

}