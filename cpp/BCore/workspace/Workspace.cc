#include "Workspace.hh"
#include "WorkspaceManager.hh"

#include <BCore/node/NodeManager.hh>
#include <BCore/object/ObjectManager.hh>
#include <BCore/workspace/WorkspaceManager.hh>

namespace py = pybind11;

namespace bemo {

ObjectID Workspace::create() {
    return WorkspaceManager::instance().create();
}

Workspace::Workspace()
    : m_objectID( ObjectID::invalid() ),
      m_tasks() {}

bool Workspace::isValid() const {
    return ObjectManager::instance().exists( getObjectID() );
}

ObjectID Workspace::createTask( const std::string& type,
                                const std::string& name ) {
    ObjectID taskId = NodeManager::instance().create( type, name );
    m_tasks.emplace_back( taskId );
    return taskId;
}

bool Workspace::removeTask( ObjectID taskId ) {
    return std::remove_if( m_tasks.begin(),
                           m_tasks.end(),
                           [&]( ObjectID id ) {
                               return id == taskId;
                           } ) != m_tasks.end();

}
}
