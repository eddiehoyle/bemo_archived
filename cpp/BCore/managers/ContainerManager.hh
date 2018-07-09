#ifndef BEMO_CONTAINERMAINAGER_HH
#define BEMO_CONTAINERMAINAGER_HH

#include <BCore/Platform.hh>
#include <BCore/container/AbstractContainer.hh>

namespace bemo {

/// Owns all container lifetimes.
class ContainerManager {

    class AbstractWrapper {
    public:
        ContainerID id() const { return m_id; }
        ContainerTypeID type() const { return m_type; }
    protected:
        ContainerID m_id;
        ContainerTypeID m_type;
    };

    template< typename T >
    class ContainerWrapper : public AbstractWrapper {
    public:
        ContainerWrapper( T container )
                : m_container( container ) {
            m_type = T::m_typeID;
        }
        T& get() { return m_container; }
    private:
        T m_container;
    };

    using ContanierIDs = std::set< ContainerID >;
    using ContainerMap = std::unordered_map< ContainerTypeID, ContanierIDs >;
    using ContainerWrappers = std::vector< AbstractWrapper* >;

public:

//    template< typename C, class... Args >
//    ContainerID create( Args&&... args ) {
//        ContainerWrapper< C >* wrapper = new ContainerWrapper< C >( C( std::forward<Args>(args)... ) );
//        EntityID id = acquire( container );
//        container->get().m_componentManager = m_componentManager;
//        container->get().m_id = id;
//        CNC_ERROR << "Created entity: " << (void*)&container->get();
//        ContainerID id = 0;
//        wrapper->get().m_id = id;
//        return id;
//    }

    template< typename C, class... Args >
    AbstractContainer* create( Args&&... args ) {
        ContainerWrapper< C >* wrapper = new ContainerWrapper< C >( C( std::forward<Args>(args)... ) );
        wrapper->get().m_id = 0;
        wrapper->get().m_manager = this;
        return &wrapper->get();
    }

    template< typename C >
    void destroy( ContainerID id ) {
//        CNC_ASSERT( id < m_containers.size() );
//        EntityContainer< T >* container = get_container< T >( id );
//        CNC_ASSERT( container != nullptr );
//        CNC_ERROR << "Deleting entity: " << (void*)&container->get();
//
//        auto type_iter = m_entities.find( container->type() );
//        CNC_ASSERT( type_iter != m_entities.end() );
//        auto id_iter = std::find( type_iter->second.begin(), type_iter->second.end(), container->id() );
//        CNC_ASSERT( id_iter != type_iter->second.end() );
//        type_iter->second.erase( id_iter );
//
//        delete m_containers[ id ];
//        m_containers[ id ] = nullptr;
    }

    AbstractContainer* getContainer( ContainerID id ) const {
        return nullptr;
    }

    AbstractContainers getContainers( ContainerIDs ids ) const {
        return AbstractContainers();
    }

    void link( ContainerID parent, ContainerID child ) {
        return;
    }

private:
    ContainerWrappers m_wrappers;
    ContainerMap m_containers;
};

}


#endif // BEMO_CONTAINERMAINAGER_HH
