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

ObjectID WorkspaceManager::create( const std::string& type, const std::string& name ) {
//    auto bp = NodeRegistry::instance().find(type);
//    BMO_ASSERT(bp != nullptr);
//    py::object obj = bp->create();
//    BDagNode* node = py::cast< BDagNode* >( obj.release() );
//    node->m_objectID = ObjectManager::instance().acquire();
//    node->m_type = type;
//    node->setName( name );
//    bp->layout(node->getObjectID());
//    m_workspaces.push_back( node );
//    return m_workspaces.back()->getObjectID();
    return ObjectID::invalid();
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