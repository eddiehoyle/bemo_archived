#ifndef BEMO_NODEMANAGER_HH
#define BEMO_NODEMANAGER_HH

#include <BCore/API.hh>
#include <BCore/internal/Table.hh>
#include <BCore/object/AbstractNode.hh>
#include <BCore/managers/ObjectManager.hh>
#include <tuple>

namespace bemo {

class AbstractCreateFunc {
public:
    virtual AbstractNode* invoke() = 0;
};

class AbstractLayoutFunc {
public:
    virtual void invoke( ObjectID id ) = 0;
};

template< typename F >
class CreateFuncWrapper : public AbstractCreateFunc {
public:
    explicit CreateFuncWrapper( F func ) : m_func( func ) {}
    AbstractNode* invoke() override { return m_func(); }
public:
    F m_func;
};

template< typename F >
class LayoutFuncWrapper : public AbstractLayoutFunc {
public:
    explicit LayoutFuncWrapper( F func ) : m_func( func ) {}
    void invoke( ObjectID id ) override { m_func( id ); }
public:
    F m_func;
};


class NodeManager {
public:

    AbstractNode* create( const NodeType& type, const NodeName& name = NodeName() );

    void remove( const ObjectID& id );

    AbstractNode* find( const ObjectID& name ) const;
    AbstractNode* find( const NodeName& name ) const;

    bool exists( const ObjectID& id ) const;

    void addBlueprint( const std::string& type,
                       AbstractCreateFunc* wrCreate,
                       AbstractLayoutFunc* wrLayout );

    AbstractCreateFunc* findCreate( const std::string& type ) const;

    AbstractLayoutFunc* findLayout( const std::string& type ) const;

private:
    std::map< std::string, std::pair< AbstractCreateFunc*, AbstractLayoutFunc* > > m_funcs;
    std::vector< AbstractNode* > m_nodes;
};

}

#endif // BEMO_NODEMANAGER_HH
