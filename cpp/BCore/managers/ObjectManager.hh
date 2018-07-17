#ifndef BEMO_OBJECTMANAGER_HH
#define BEMO_OBJECTMANAGER_HH

#include <BCore/Platform.hh>
#include <BCore/object/AbstractObject.hh>

namespace bemo {

//class ObjectManager {
//
//    class IObjectContainer {
//    public:
//        explicit IObjectContainer( TypeID typeID, ObjectID objectID )
//            : m_typeID( typeID ),
//            m_objectID( objectID ) {}
//        virtual ~IObjectContainer() {}
//
//    private:
//        TypeID m_typeID;
//        ObjectID m_objectID;
//    };
//
//    template< typename O >
//    class ObjectContainer : public IObjectContainer {
//    public:
//        ObjectContainer( TypeID typeID, ObjectID objectID )
//                : IObjectContainer( typeID, objectID ) {}
//        O& get() const { return m_object; }
//    private:
//        O m_object;
//    };

//public:
//
//    /// TODO
//    /// \tparam O
//    /// \tparam Args
//    /// \param args
//    /// \return
//    template< typename O, class... Args >
//    ObjectID create( Args&&... args ) { return 0; }
//
//    /// TODO
//    void destroy( ObjectID id ) {}

//private:
//    ObjectID acquire() { return 0; }
//};

class ObjectManager {};



}

#endif // BEMO_OBJECTMANAGER_HH
