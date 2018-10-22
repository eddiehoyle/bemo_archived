#include "ObjectManager.hh"

namespace bemo {

ObjectManager& ObjectManager::instance() {
    static ObjectManager mgr;
    return mgr;
}

ObjectID ObjectManager::acquire() {
    return ObjectID( m_table.acquire() );
}

void ObjectManager::release( const ObjectID& id ) {
    m_table.release( id.m_handle );
}

bool ObjectManager::exists( const ObjectID& id ) {
    return m_table.exists( id.m_handle );
}

}
