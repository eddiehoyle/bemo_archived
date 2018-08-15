#ifndef BEMO_ABSTRACTMANAGEDOBJECT_HH
#define BEMO_ABSTRACTMANAGEDOBJECT_HH

#include <BCore/Platform.hh>
#include <BCore/internal/Handle.hh>

namespace bemo {

//using NodeID = Handle< ObjectType::Node, u32, 16, 16 >;
//
//class AbstractObject {
//public:
//    ObjectID objectID() const { return m_objectID; }
//protected:
//    virtual ~AbstractObject() = default;
//    bool operator==( const AbstractObject& rhs ) { return this->m_objectID == rhs.objectID(); }
//protected:
//    ObjectID m_objectID;
//    PlugManager* m_manager;
//};
class BObjectManager;

class BObject {
    friend class BObjectManager;
public:
    BObject() = default;
    ~BObject() = default;
    ObjectType type() const { return ObjectType::Invalid; }
    const char* typeStr () const { return ""; }
private:
    std::size_t m_index;
    ObjectType m_type;
};

class BObjectManager {
public:
    BObjectManager() = default;
    BObject acquire( ObjectType type ) {
        BObject obj;
        obj.m_index = s_count++;
        obj.m_type = type;
        m_objects.push_back( obj );
        return obj;
    }
private:
    std::size_t s_count;
    std::vector< BObject > m_objects;
};

class BNode {
    friend class BNodeManager;
private:
    BObject m_object;
};

class BNodeManager {
public:
    BNode create() {
        BNode node;
        node.m_object = BObjectManager().acquire( ObjectType::Node );
        return node;
    }

};

}

#endif // BEMO_ABSTRACTMANAGEDOBJECT_HH
