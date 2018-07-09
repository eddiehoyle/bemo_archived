#include "AbstractContainer.hh"
#include <BCore/managers/ContainerManager.hh>

namespace bemo {

AbstractContainer* AbstractContainer::getParent() const {
    return m_manager->getContainer( m_parent );
}

AbstractContainers AbstractContainer::getChildren() const {
    return m_manager->getContainers( m_children );
}

void AbstractContainer::setParent( AbstractContainer* parent ) {
    return m_manager->link( parent->id(), this->id() );
}

}