#ifndef BEMO_CONTAINERMAINAGER_HH
#define BEMO_CONTAINERMAINAGER_HH

#include <BCore/Bemo.hh>

#include <BCore/util/Assert.hh>
#include <BCore/util/Log.hh>
#include <BCore/Platform.hh>
//#include <BCore/object/Object.hh>

namespace bemo {

/* Owns all managed object lifetimes.
 * Thoughts:
 *  Could this create all objects? Handle all allocations? Eg:
 *   PlugManager->create< Graph >();
 *   PlugManager->create< Node >();
 *   PlugManager->create< Connection >();
 *  All object types and ids will be unique...
 *   m_objects {
 *      Connections: [0, 1, ..., n],
 *      Graph:       [0, 1, ..., n],
 *      Group:       [0, 1, ..., n],
 *      Node:        [0, 1, ..., n],
 *      Plug:        [0, 1, ..., n],
 *   }
 */
//
//
//template< typename T, typename H >
//class ContainerManager : public AbstractManager< T, H > {
//
//    using NodeType = T;
//    using HandleType = H;
//
//public:
//    NodeType create() override {
//        HandleType id = this->m_table.acquire( nullptr );
//        return NodeType( id );
//    }
//    void destroy( const NodeType& graph ) override {
//        this->m_table.release( graph.objectID() );
//    }
//};

//class ContainerManager {
//
//    class Wrapper {
//    public:
//        virtual ~Wrapper() = default;
//        ContainerID id() const { return m_nodeID; }
//        ContainerTypeID type() const { return m_type; }
//    protected:
//        ContainerID m_nodeID;
//        ContainerTypeID m_type;
//    };
//
//    template< typename C >
//    class ContainerWrapper : public Wrapper {
//    public:
//        ContainerWrapper( C container ) : m_container( container ) {
//            this->m_nodeID = container.id();
//            this->m_type = C::TYPEID;
//        }
//        C& get() { return m_container; }
//    private:
//        C m_container;
//    };
//
//    using ContanierIDSet = std::set< ContainerID >;
//    using ContainerMap = std::map< ContainerTypeID, ContanierIDSet >;
//    using ContainerWrappers = std::vector< Wrapper* >;
//
//public:
//
//    template< typename C, class... Args >
//    ContainerID create( Args&&... args ) {
//
//        ContainerID id = acquire< C >();
//        auto wrapper = new ContainerWrapper< C >( C( id, std::forward<Args>(args)... ) );
//        wrapper->get().m_nodeID = id;
//        wrapper->get().m_manager = this;
//
//        BMO_ERROR << "created: type=" << C::TYPEID << ", id=" << id;
//
//        m_containers[ C::TYPEID ].insert( id );
//        m_wrappers.push_back( wrapper );
//
//        return id;
//    }
//
//    template< typename C >
//    void release( ContainerID id ) {
//
//        BMO_ASSERT( m_containers.find( C::TYPEID ) != m_containers.end() );
//        auto wrapper = getWrapper< C >( id );
//        BMO_ASSERT( wrapper != nullptr );
//        BMO_ERROR << "Deleting: type=" << wrapper->type() << ", id=" << wrapper->id();
//        delete wrapper;
//
//        // Cleanup
//        m_containers[ C::TYPEID ].erase( m_containers[ C::TYPEID ].find( id ) );
//        m_wrappers.erase( std::find( m_wrappers.begin(), m_wrappers.end(), wrapper ) );
//    }
//
//    template< typename C >
//    inline bool exists( ContainerID id ) {
//        return m_containers[ C::TYPEID ].find( id ) != m_containers.end();
//    }
//
//private:
//
//    template< typename C >
//    Wrapper* getWrapper( ContainerID id ) const {
//        for ( auto wrapper : m_wrappers ) {
//            if ( wrapper->type() == C::TYPEID &&  wrapper->id() == id ) {
//                return wrapper;
//            }
//        }
//        return nullptr;
//    }
//
//    template< typename C >
//    inline ContainerID acquire() {
//        return m_containers[ C::TYPEID ].size();
//    }
//
//private:
//    ContainerWrappers m_wrappers;
//    ContainerMap m_containers;
//};

}


#endif // BEMO_CONTAINERMAINAGER_HH
