#include "AbstractNode.hh"

#include <BCore/Bemo.hh>
#include <BCore/Variant.hh>
#include <BCore/object/Plug.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/managers/PlugManager.hh>
#include <BCore/system/ConnectionSystem.hh>

namespace bemo {

AbstractNode::AbstractNode()
        : m_id(),
          m_nodeType( "invalid" ) {}

AbstractNode::~AbstractNode() {
    BMO_ERROR << "dtor=" << (void*)this;
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
        m_objectName = uniqueName;
    } else {
        m_objectName = name;
    }
}

NodeManager* AbstractNode::getManager() const {
    retun m_manager;
}

//void AbstractNode::setInput( const std::string& name, const Variant& var ) {
//    setPlugValue( this, name, PlugDirectionPolicy::Input, var );
//}
//
//void AbstractNode::setOutput( const std::string& name, const Variant& var ) {
//    setPlugValue( this, name, PlugDirectionPolicy::Output, var );
//}
//
//Variant AbstractNode::getInput( const PlugName& name ) {
//    return getPlugValue( this, name, PlugDirectionPolicy::Input );
//}
//
//Variant AbstractNode::getOutput( const PlugName& name ) {
//    return getPlugValue( this, name, PlugDirectionPolicy::Output );
//}
//
//bool AbstractNode::hasInput( const PlugName& name ) const {
//    return hasPlug( this, name, PlugDirectionPolicy::Input );
//}
//
//bool AbstractNode::hasOutput( const PlugName& name ) const {
//    return hasPlug( this, name, PlugDirectionPolicy::Output );
//}
//
//std::vector< PlugName > AbstractNode::getInputs() const {
//    return BMO_PlugManager->getOwnedBy( getID(), PlugDirectionPolicy::Input );
//}
//
//std::vector< PlugName > AbstractNode::getOutputs() const {
//    return BMO_PlugManager->getOwnedBy( getID(), PlugDirectionPolicy::Output );
//}

int AbstractNode::execute() {
    return -1;
}


}