#include "WorkspaceManager.hh"

#include <BCore/Assert.hh>
#include <BCore/workspace/Workspace.hh>
#include <BCore/object/ObjectManager.hh>

namespace py = pybind11;

namespace bemo {

WorkspaceManager& WorkspaceManager::instance() {
    static WorkspaceManager mgr;
    return mgr;
}

ObjectID WorkspaceManager::create() {
    Workspace* workspace = new Workspace();
    workspace->m_objectID = ObjectManager::instance().acquire();
    m_workspaces.emplace_back( workspace );
    return workspace->getObjectID();
}

Workspace* WorkspaceManager::find( ObjectID id ) const {
    auto iter = std::find_if( m_workspaces.begin(),
                              m_workspaces.end(),
                              [&id]( Workspace* ws ) {
                                  return ws->getObjectID() == id;
                              });
    return iter != m_workspaces.end() ? *iter : nullptr;
}

}