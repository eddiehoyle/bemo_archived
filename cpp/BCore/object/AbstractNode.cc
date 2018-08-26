#include "AbstractNode.hh"

#include <BCore/API.hh>
#include <BCore/Variant.hh>
#include <BCore/object/Plug.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/system/ConnectionSystem.hh>

namespace bemo {


static void setPlugValue( AbstractNode* node,
                          const PlugName& name,
                          PlugDirection direction,
                          const Variant& var ) {
    Plug* plug = BMO_PlugManager->find( node->getID(), name, direction );
    if ( plug && plug->isValid() ) {
        if ( plug->isStrict() && ( plug->getType() == var.type() ) ) {
            plug->setValue( var );
        }
    }
}

static const Variant& getPlugValue( AbstractNode* node,
                                    const PlugName& name,
                                    PlugDirection direction ) {
    Plug* plug = BMO_PlugManager->find( node->getID(), name, direction );
    if ( plug && plug->isValid() ) {
        return plug->getValue();
    }
    return Plug::invalid().getValue();
}

AbstractNode::AbstractNode()
        : m_id(),
          m_nodeType( "invalid" ) {}

AbstractNode::~AbstractNode() {
    BMO_NodeManager->remove( getID() );
}

void AbstractNode::setName( const NodeName& name ) {
    if ( BMO_NodeManager->find( name ) != nullptr ) {
        std::size_t index = 0;
        NodeName uniqueName = name;
        bool exists = true;
        while ( exists ) {
            uniqueName = name + std::to_string( index++ );
            exists = BMO_NodeManager->find( uniqueName ) != nullptr;
        }
        m_nodeName = uniqueName;
    } else {
        m_nodeName = name;
    }
}

void AbstractNode::setInput( const std::string& name, const Variant& var ) {
    setPlugValue( this, name, PlugDirection::Input, var );
}

void AbstractNode::setOutput( const std::string& name, const Variant& var ) {
    setPlugValue( this, name, PlugDirection::Output, var );
}

ObjectID AbstractNode::getInput( const PlugName& name ) {
    Plug* plug = BMO_PlugManager->find( m_id, name, PlugDirection::Input );
    if ( plug && plug->isValid() ) {
        return plug->getID();
    }
    return ObjectID::invalid();
}

Variant AbstractNode::getOutput( const PlugName& name ) {
    return getPlugValue( this, name, PlugDirection::Output );

}

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