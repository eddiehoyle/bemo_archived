#include "Object.hh"
#include "ObjectManager.hh"

namespace bemo {

Object::~Object() {
    ObjectManager::instance().release( getObjectID() );
    BMO_ERROR << "dead";
}

bool Object::isValid() const {
    return ObjectManager::instance().exists( getObjectID() );
}

}