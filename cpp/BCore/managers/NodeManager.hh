#ifndef BEMO_NODEMANAGER_HH
#define BEMO_NODEMANAGER_HH

#include "AbstractManager.hh"
#include <BCore/object/Node.hh>
#include <BCore/object/Object.hh>

namespace bemo {

class NodeManager {

    class AbstractWrapper {
    public:
        virtual ~AbstractWrapper() = default;
    };

    template< typename T >
    class ObjectWrapper : AbstractWrapper {
    public:
        explicit ObjectWrapper( const T& object )
            : m_object( object ) {}
        T& get() { return m_object; }
    private:
        T m_object;
    };

public:

    template< typename T, typename... Args >
    ObjectID create( Args&&... args ) {
        ObjectID id = this->m_table.acquire( new ObjectWrapper< T >( T( std::forward< Args >( args )... ) ) );
        T* object = static_cast< ObjectWrapper< T >* >( m_table[ id ] )->get();
        object->m_objectID = id;
        return id;
    }

private:
    HandleTable< AbstractWrapper, ObjectID > m_table;
    std::map< std::string, TypeID > m_nodeTypes;
    std::map< std::string, TypeID > m_nodeLayouts;
};

}
#endif // BEMO_NODEMANAGER_HH
