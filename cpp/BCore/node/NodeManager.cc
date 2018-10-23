#include <BCore/Assert.hh>
#include <BCore/object/ObjectManager.hh>
#include "NodeManager.hh"
#include "NodeRegistry.hh"

#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace py = pybind11;

namespace bemo {

NodeManager& NodeManager::instance() {
    static NodeManager mgr;
    return mgr;
}

ObjectID NodeManager::create( const std::string& type, const std::string& name ) {
    auto bp = NodeRegistry::instance().find(type);
    BMO_ASSERT(bp != nullptr);
    py::object obj = bp->create();
    BDagNode* node = py::cast< BDagNode* >( obj.release() );
    node->m_objectID = ObjectManager::instance().acquire();
    node->m_type = type;
    node->setName( name );
    bp->layout(node->getObjectID());
    m_nodes.push_back( node );
    return m_nodes.back()->getObjectID();
}

BDagNode* NodeManager::find( ObjectID id ) const {
    auto iter = std::find_if( m_nodes.begin(),
                              m_nodes.end(),
                              [&id]( BDagNode* node ) {
                                  return node->getObjectID() == id;
                              });
    return iter != m_nodes.end() ? *iter : nullptr;
}

std::vector< BDagNode* > NodeManager::list() const {
    return m_nodes;
}

}