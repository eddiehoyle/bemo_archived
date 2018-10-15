#include "PlugSystem.hh"
#include <old/BCore/Bemo.hh>
#include <old/BCore/util/Assert.hh>
#include <old/BCore/managers/PlugManager.hh>
#include <old/BCore/managers/NodeManager.hh>
#include <old/BCore/object/AbstractNode.hh>

namespace bemo {

static void setPlugValue( ObjectID plugID,
                          const PlugName& name,
                          PlugDirectionPolicy direction,
                          const Variant& var ) {
    AbstractNode* node = BMO_NodeManager->find( plugID );
    Plug* plug = BMO_PlugManager->find( node->getID(), name, direction );
    BMO_ASSERT( node && plug );
    if ( plug && plug->isValid() ) {
//        // TODO: Implement plug type policies
//        if ( plug->isStrict() && ( plug->getType() == var.type() ) ) {
//            plug->setValue( var );
//        }
        plug->setValue( var );
    }
}

static const Variant& getPlugValue( ObjectID plugID,
                                    const PlugName& name,
                                    PlugDirectionPolicy direction ) {
    AbstractNode* node = BMO_NodeManager->find( plugID );
    Plug* plug = BMO_PlugManager->find( node->getID(), name, direction );
    BMO_ASSERT( node && plug );
    if ( plug && plug->isValid() ) {
        return plug->getValue();
    }
    return Plug::invalid().getValue();
}

static bool hasPlug( ObjectID plugID,
                     const PlugName& name,
                     PlugDirectionPolicy direction ) {
    AbstractNode* node = BMO_NodeManager->find( plugID );
    BMO_ASSERT( node != nullptr );
    return BMO_PlugManager->find( node->getID(), name, direction ) != nullptr;
}

void PlugSystem::setInput( const std::string& name, const Variant& var ) {
    setPlugValue( m_id, name, PlugDirectionPolicy::Input, var );
}

void PlugSystem::setOutput( const std::string& name, const Variant& var ) {
    setPlugValue( m_id, name, PlugDirectionPolicy::Output, var );
}

Variant PlugSystem::getInput( const PlugName& name ) {
    return getPlugValue( m_id, name, PlugDirectionPolicy::Input );
}

Variant PlugSystem::getOutput( const PlugName& name ) {
    return getPlugValue( m_id, name, PlugDirectionPolicy::Output );
}

bool PlugSystem::hasInput( const PlugName& name ) const {
    return hasPlug( m_id, name, PlugDirectionPolicy::Input );
}

bool PlugSystem::hasOutput( const PlugName& name ) const {
    return hasPlug( m_id, name, PlugDirectionPolicy::Output );
}

std::vector< PlugName > PlugSystem::getInputs() const {
    return BMO_PlugManager->getOwnerPlugNames( m_id,
                                               PlugDirectionPolicy::Input );
}

std::vector< PlugName > PlugSystem::getOutputs() const {
    return BMO_PlugManager->getOwnerPlugNames( m_id,
                                               PlugDirectionPolicy::Output );
}

}