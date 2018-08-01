
#include "pybemo.hh"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include <BCore/API.hh>
#include <BCore/util/Log.hh>
#include <BCore/managers/NodeRegistry.hh>
#include <BCore/managers/NodeManager.hh>

#include <memory>
#include <sstream>
#include <string>
#include <list>

namespace py = pybind11;

using namespace bemo;
//
//NodeManager* BMO_NodeManager = nullptr;
//
//AbstractNode::AbstractNode( int value )
//    : m_value( value ),
//    m_nodeID( 0 ),
//    m_typeID( "invalid" ) {}
//
//int AbstractNode::value() const { return m_value; }
//std::string AbstractNode::typeID() const { return m_typeID; }
//int AbstractNode::nodeID() const { return m_nodeID; }
//
//NodeManager::NodeManager() : m_creators() {
//    BMO_ERROR << "NodeManager started!";
//}
//
//void NodeManager::add( const std::string& type, CreateFunc func ) {
//    BMO_ERROR << "adding... " << type;
//    m_creators[ type ] = func;
//}
//
//AbstractNode* NodeManager::create( const std::string& type ) {
//    auto iter = m_creators.find( type );
//    if ( iter != m_creators.end() ) {
//        auto func = iter->second;
//        AbstractNode* node = func();
//        node->m_nodeID = m_nodes.size();
//        node->m_typeID = type;
//        m_nodes.emplace_back( node );
//        return node;
//    }
//    return nullptr;
//}
//
//void init() {
//    BMO_ERROR << "init!";
//    if ( BMO_NodeManager == nullptr ) {
//        BMO_NodeManager = new NodeManager();
//        BMO_NodeManager->add( "cpp", []()->AbstractNode*{
//            return new CppNode( 3 );
//        });
//    }
//}


PYBIND11_MODULE(pybemo, m) {

    m.def("init", [](){
        initialize();
        BMO_NodeRegistry->add( "cpp", []()->AbstractNode*{
            return new AbstractNode();
        });
    });
    m.def("add", []( const std::string& type, CreatorFunc func ){
        BMO_NodeRegistry->add( type, func );
    });
//    m.def("create", []( const std::string& type )->std::unique_ptr< AbstractNode, py::nodelete >{
//        return std::unique_ptr<AbstractNode, py::nodelete>( BMO_NodeManager->create( type ) );
//    });
    m.def("create", []( const std::string& type )->AbstractNode*{
        return BMO_NodeManager->create( type );
    });

    py::class_<AbstractNode, std::unique_ptr<AbstractNode, py::nodelete>>(m, "AbstractNode")
            .def(py::init<>())
            .def("nodeID", &AbstractNode::nodeID)
            .def("typeID", &AbstractNode::typeID)
            .def("execute", &AbstractNode::execute)
            .def("__repr__", []( const AbstractNode& n ){
                std::stringstream ss;
                ss << "<AbstractNode(";
                ss << "addr=" << (void*)&n;
                ss << ", id=" << n.nodeID();
                ss << ", type=" << n.typeID();
                ss << ")>";
                return ss.str();
            });








//    py::class_<BaseA, std::shared_ptr<BaseA>>(m, "BaseA")
//            .def(py::init<int>())
//            .def("value", &BaseA::value);
//

//    py::class_<AddNode>(m, "Dog", animal)
//            .def(py::init<>());

//    py::class_<Example>(m, "Example")
//            // Bind the factory function as a constructor:
//            .def(py::init(&Example::create))
//            .def("execute", &Example::execute)
                    // Bind a lambda function returning a pointer wrapped in a holder:
//            .def(py::init([](std::string arg) {
//                return std::unique_ptr<Example>(new Example(arg));
//            }))
//                    // Return a raw pointer:
//            .def(py::init([](int a, int b) { return new Example(a, b); }))
//                    // You can mix the above with regular C++ constructor bindings as well:
//            .def(py::init<double>())
//            ;

//    py::class_<Example>(m, "Example")
//            // Bind the factory function as a constructor:
//            .def(py::init(&Example::create))
//                    // Bind a lambda function returning a pointer wrapped in a holder:
//            .def(py::init([](std::string arg) {
//                return std::unique_ptr<Example>(new Example(arg));
//            }))
//                    // Return a raw pointer:
//            .def(py::init([](int a, int b) { return new Example(a, b); }))
//                    // You can mix the above with regular C++ constructor bindings as well:
//            .def(py::init<double>());

//
//    py::class_<Node, std::shared_ptr<Node> >(m, "Node")
//            .def(py::init<const std::string &>())
//            .def("set_name", &Node::set_name)
//            .def("get_name", &Node::get_name)
//            .def("execute", &Node::execute)
//            .def("__repr__",
//                 [](const Node &a) {
//                     return "<pybemo.Node '" + a.get_name() + "'>";
//                 }
//            );
//
//    py::class_<Graph, std::shared_ptr<Graph> >(m, "Graph")
//            .def(py::init<>())
//            .def("add", &Graph::add)
//            .def("remove", &Graph::remove)
//            .def("get_count", &Graph::get_count)
//            .def("execute", &Graph::execute)
//            .def("__repr__",
//                 [](const Graph &g) {
//                     return "<pybemo.Graph count=" + std::to_string( g.get_count() ) + ">";
//                 }
//            );
//
//
//
//    m.def("create_node", &NodeRegistry::create, py::arg("name"));
//    m.def("create_node", &create_node, py::arg("name"));
//    m.def("read_node", &read_node, py::arg("container"));
//
//
//    py::class_<GraphManager, std::unique_ptr<GraphManager, py::nodelete>>(m, "GraphManager")
//            .def(py::init([]() {
//                BMO_ERROR << "Python : Got GraphManager=" << (void*)BMO_GraphManager;
//                return BMO_GraphManager; }))
//            .def("get_graph", &GraphManager::get_graph );






//    py::class_<GraphManager, std::shared_ptr<GraphManager> >(m, "GraphManager")
//            .def(py::init<>())
//            .def("get_graph", &GraphManager::get_graph);
//    py::class_<GraphManager>(m, "GraphManager")
//            .def(py::init([]() {
//                BMO_ERROR << "Python : Got GraphManager=" << (void*)BMO_GraphManager;
//                return BMO_GraphManager; }))
//            .def("get_graph", &GraphManager::get_graph );


//            .def("__new__",
//                 []() {
//                BMO_ERROR << "Returning GraphManager=" << (void*)BMO_GraphManager;
//                return BMO_GraphManager;
//                } );

//    py::class_<GraphManager, std::unique_ptr<GraphManager, py::nodelete>>(m, "GraphManager")
//            .def(py::init<>());

//    .def("__new__",
//                 []() { return std::unique_ptr<GraphManager, py::nodelete >( &GraphManager::instance() ); },
//                 py::return_value_policy::reference_internal );

//    py::class_<GraphManager, std::unique_ptr<GraphManager, py::nodelete>>(m, "GraphManager")
//            .def(py::init(&GraphManager::instance), py::return_value_policy::reference);

//    m.def("get_ui_graph", &get_ui_graph);
}






//std::shared_ptr<BaseA> create_instance() {
//    return std::shared_ptr< BaseA >( new BaseA(1) );
//}
//
//std::shared_ptr<BaseA> check_creation(py::function py_factory) {
//    std::shared_ptr<BaseA> obj;{
//        py::object py_obj = py_factory();
//        obj = py::cast<std::shared_ptr<BaseA>>(py_obj);
//    }
//    return obj;
//}
