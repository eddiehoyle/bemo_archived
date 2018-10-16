#ifndef BEMO_PLUGINSYSTEM_HH
#define BEMO_PLUGINSYSTEM_HH

#include <BCore/object/ObjectID.hh>
#include <BCore/object/Node.hh>

#include <memory>
#include "PluginManager.hh"

namespace bemo {

// IKEA
// Order number: 314376809

template< typename F >
class CreateNodeFuncWrapper : public AbstractCreateFuncWrapper {
public:
    explicit CreateNodeFuncWrapper( F func ) : m_func( func ) {}
    void* get() { return static_cast< void* >( &m_func ); }
private:
    F m_func;
};


//
//class AbstractCreateFunc {
//public:
//    virtual ~AbstractCreateFunc() = default;
//    virtual Object* invoke() = 0;
//};
//
//class AbstractLayoutFunc {
//public:
//    virtual ~AbstractLayoutFunc() = default;
//    virtual void invoke( ObjectID id ) = 0;
//};
//
//template< typename F >
//class CreateFuncWrapper : public AbstractCreateFunc {
//public:
//    explicit CreateFuncWrapper( F func ) : m_func( func ) {}
//    Object* invoke() override { return m_func(); }
//private:
//    F m_func;
//};
//
//template< typename F >
//class LayoutFuncWrapper : public AbstractLayoutFunc {
//public:
//    explicit LayoutFuncWrapper( F func ) : m_func( func ) {}
//    void invoke( ObjectID id ) override { m_func( id ); }
//private:
//    F m_func;
//};


class PluginSystem {
public:
    explicit PluginSystem( const ObjectID& id ) : m_id( id ) {

    }

    void setHeader( const std::string& name,
                    const std::string& description,
                    const std::string& icon ) {}

//    template< typename T >
    void registerNode( const std::string& name, std::function<Object*()> fnCreate ) {
        BMO_ERROR << "registerNode: " << name;
        registerNode2( name, new CreateNodeFuncWrapper< std::function<Object*()> >( fnCreate ) );
    }

    template< typename T >
    T* create( const std::string& name ) {

        // TODO:
        // Fix this, it's crashing when being dereferenced
        auto f = PluginManager::instance().get(name);

//        auto fptr = *((std::function<Object*()>*)PluginManager::instance().get(name));
//        BMO_ERROR << "got valid functor: " << ( fptr != nullptr );
//        return static_cast<T*>( fptr() );
        return nullptr;
    }

private:

    std::map< std::string, AbstractCreateFuncWrapper* > m_wrappers;

    /// This can be hidden
    void registerNode2( const std::string& name, AbstractCreateFuncWrapper* wrapper ) {
        PluginManager::instance().addWrapper( m_id, name, wrapper );
    }

//        BMO_NodeManager->addBlueprint( name,
//                                       new CreateFuncWrapper< C >( fnCreate ),
//                                       new LayoutFuncWrapper< L >( fnLayout ) );
//}

private:
    ObjectID m_id;

};


}

#endif // BEMO_PLUGINSYSTEM_HH
