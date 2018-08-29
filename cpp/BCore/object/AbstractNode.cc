#include "AbstractNode.hh"

#include <BCore/Bemo.hh>
#include <BCore/Variant.hh>
#include <BCore/object/Plug.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/system/ConnectionSystem.hh>

namespace bemo {


static void setPlugValue( AbstractNode* node,
                          const PlugName& name,
                          PlugDirectionPolicy direction,
                          const Variant& var ) {
    Plug* plug = BMO->getPlugManager()->find( node->getID(), name, direction );
    if ( plug && plug->isValid() ) {
//        // TODO: Implement plug type policies
//        if ( plug->isStrict() && ( plug->getType() == var.type() ) ) {
//            plug->setValue( var );
//        }
        plug->setValue( var );
    }
}

static const Variant& getPlugValue( AbstractNode const* node,
                                    const PlugName& name,
                                    PlugDirectionPolicy direction ) {
    Plug* plug = BMO->getPlugManager()->find( node->getID(), name, direction );
    if ( plug && plug->isValid() ) {
        return plug->getValue();
    }
    return Plug::invalid().getValue();
}

static bool hasPlug( AbstractNode const* node,
                     const PlugName& name,
                     PlugDirectionPolicy direction ) {
    return BMO->getPlugManager()->find( node->getID(), name, direction ) != nullptr;
}

AbstractNode::AbstractNode()
        : m_id(),
          m_nodeType( "invalid" ) {}

AbstractNode::~AbstractNode() {
    BMO->getNodeManager()->remove( getID() );
}

void AbstractNode::setName( const NodeName& name ) {
    if ( BMO->getNodeManager()->find( name ) != nullptr ) {
        std::size_t index = 0;
        NodeName uniqueName = name;
        bool exists = true;
        while ( exists ) {
            uniqueName = name + std::to_string( index++ );
            exists = BMO->getNodeManager()->find( uniqueName ) != nullptr;
        }
        m_nodeName = uniqueName;
    } else {
        m_nodeName = name;
    }
}

void AbstractNode::setInput( const std::string& name, const Variant& var ) {
    setPlugValue( this, name, PlugDirectionPolicy::Input, var );
}

void AbstractNode::setOutput( const std::string& name, const Variant& var ) {
    setPlugValue( this, name, PlugDirectionPolicy::Output, var );
}

Variant AbstractNode::getInput( const PlugName& name ) {
    return getPlugValue( this, name, PlugDirectionPolicy::Input );
}

Variant AbstractNode::getOutput( const PlugName& name ) {
    return getPlugValue( this, name, PlugDirectionPolicy::Output );
}

bool AbstractNode::hasInput( const PlugName& name ) const {
    return hasPlug( this, name, PlugDirectionPolicy::Input );
}

bool AbstractNode::hasOutput( const PlugName& name ) const {
    return hasPlug( this, name, PlugDirectionPolicy::Output );
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

int AbstractNode::execute() {
    return -1;
}


}