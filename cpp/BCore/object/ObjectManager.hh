#ifndef BEMO_OBJECTMANAGER_HH
#define BEMO_OBJECTMANAGER_HH

#include "Table.hh"
#include "ObjectID.hh"
#include "Object.hh"

namespace bemo {

class ObjectManager {
public:
    static ObjectManager& instance();
public:
    ObjectManager(ObjectManager const&) = delete;
    void operator=(ObjectManager const&) = delete;
public:
    ObjectID acquire();
    void release( const ObjectID& id );
    bool exists( const ObjectID& id );
private:
    ObjectManager() {}
    HandleTable< ObjectHandle > m_table;
};

}

#endif // BEMO_OBJECTMANAGER_HH
