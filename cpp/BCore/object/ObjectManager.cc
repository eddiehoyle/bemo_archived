#include "ObjectManager.hh"

namespace bemo {

ObjectManager& ObjectManager::instance() {
    static ObjectManager mgr;
    return mgr;
}

ObjectID ObjectManager::acquire() {
    ObjectID obj( m_table.acquire() );
    return obj;
}

void ObjectManager::release( const ObjectID& id ) {
    BMO_ERROR << "releasing id=" << id;
    m_table.release( id.m_handle );
}

bool ObjectManager::exists( const ObjectID& id ) {
    return m_table.exists( id.m_handle );
}

}
