#include "AbstractNode.hh"

#include <BCore/API.hh>
#include <BCore/object/Plug.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/system/ConnectionSystem.hh>

namespace bemo {

AbstractNode::AbstractNode()
        : m_id(),
          m_nodeType( "invalid" ) {}

AbstractNode::~AbstractNode() {
    BMO_NodeManager->remove( getID() );
}

void AbstractNode::setInput( const std::string& name,
                             const Variant& var ) {
    Plug * plug = BMO_PlugManager->find( m_id, name );
    if ( plug != nullptr ) {
        plug->setValue( var );
    }
}

void AbstractNode::setOutput( const std::string& name,
                              const Variant& var ) {}

void AbstractNode::connect( const PlugName& sourcePlugName,
                            const ObjectID& targetID,
                            const PlugName& targetPlugName ) {
    ConnectionSystem fnCon( m_id );
    fnCon.connect( sourcePlugName, targetID, targetPlugName );
}

void AbstractNode::disconnect( const PlugName& sourcePlugName,
                               const ObjectID& targetID,
                               const PlugName& targetPlugName ) {
    ConnectionSystem fnCon( m_id );
    fnCon.disconnect( sourcePlugName, targetID, targetPlugName );
}


}