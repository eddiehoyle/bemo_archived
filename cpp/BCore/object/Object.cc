#include "Object.hh"
#include "ObjectManager.hh"

namespace bemo {

Object::~Object() {
    ObjectManager::instance().release( getObjectID() );
}

bool Object::isValid() const {
    return ObjectManager::instance().exists( getObjectID() );
}

}