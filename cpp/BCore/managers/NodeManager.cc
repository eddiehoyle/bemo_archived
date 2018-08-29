#include "NodeManager.hh"
#include <BCore/managers/ObjectManager.hh>

namespace bemo {

AbstractNode* NodeManager::create( const NodeType& type, const NodeName& name ) {
    auto fnCreate = findCreate( type );
    auto fnLayout = findLayout( type );
    if ( fnCreate && fnLayout ) {
        AbstractNode* node = fnCreate->invoke();
        node->m_id = BMO->getObjectManager()->acquire( ObjectType::Node );
        node->m_nodeType = type;
        node->m_nodeName = !name.empty() ? name : ( type + std::to_string( m_nodes.size() ) );
        fnLayout->invoke( node->m_id );
        m_nodes.push_back( node );
        return node;
    }
    return nullptr;
}

void NodeManager::remove( const ObjectID& id ) {
    auto iter = std::find_if( m_nodes.begin(),
                              m_nodes.end(),
                              [&]( AbstractNode* n )->bool{
                                  return n->getID() == id;
                              });
    if ( iter != m_nodes.end() ) {
        BMO->getObjectManager()->release( ( *iter )->getID() );
        ( *iter )->m_id = ObjectID();
        m_nodes.erase( iter );
    }
}

AbstractNode* NodeManager::find( const ObjectID& id ) const {
    auto iter = std::find_if( m_nodes.begin(),
                              m_nodes.end(),
                              [&]( AbstractNode* n )->bool{
                                  return n->getID() == id;
                              });
    if ( iter != m_nodes.end() ) {
        return *iter;
    }
    return nullptr;
}

AbstractNode* NodeManager::find( const NodeName& name ) const {
    auto iter = std::find_if( m_nodes.begin(),
                              m_nodes.end(),
                              [&]( AbstractNode* n )->bool{
                                  return n->getName() == name;
                              });
    return ( iter != m_nodes.end() ) ? *iter : nullptr;
}


bool NodeManager::exists( const ObjectID& id ) const {
    return BMO->getObjectManager()->exists( id );
}

void NodeManager::addBlueprint( const std::string& type,
                   AbstractCreateFunc* wrCreate,
                   AbstractLayoutFunc* wrLayout ) {
    m_funcs[ type ] = std::pair< AbstractCreateFunc*, AbstractLayoutFunc* >( wrCreate, wrLayout );
}

AbstractCreateFunc* NodeManager::findCreate( const std::string& type ) const {
    auto iter = m_funcs.find( type );
    if ( iter != m_funcs.end() ) {
        return iter->second.first;
    }
    return nullptr;
}

AbstractLayoutFunc* NodeManager::findLayout( const std::string& type ) const {
    auto iter = m_funcs.find( type );
    if ( iter != m_funcs.end() ) {
        return iter->second.second;
    }
    return nullptr;
}

}