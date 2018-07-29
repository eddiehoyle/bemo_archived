
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
//#include <pybind11/factory.h>

#include <memory>

//#include <BCore/API.hh>

#include <memory>
#include <string>
#include <BCore/util/Log.hh>

namespace py = pybind11;
using namespace bemo;

int add(int i, int j) {
    return i + j;
}
//
//class Example {
//private:
//    Example(int a) : m_id(a) {} // private constructor
//public:
//    // Factory function - returned by value:
//    static Example* create(int a) { return new Example(a); }
//    int execute() { return -1; }
//private:
//    int m_id;
//};

class MyManager;

class BaseNode {

//    friend class MyManager;
//
public:
//    virtual ~BaseNode() = default;
    virtual int execute() { return -1; }
//    virtual int nodeTypeID() const { return 0; }
//    int objectID() const { return m_nodeID; }
//private:
//    int m_nodeID;
};

//class PyBaseNode : public BaseNode {
//public:
//    /* Inherit the constructors */
//    using BaseNode::BaseNode;
//
//    /* Trampoline (need one for each virtual function) */
//    int execute() override {
//        PYBIND11_OVERLOAD_PURE(
//                int, /* Return type */
//                BaseNode,      /* Parent class */
//                execute,          /* Name of function in C++ (must match Python name) */
//        );
//    }
//
//    int nodeTypeID() const override {
//        PYBIND11_OVERLOAD_PURE(
//                int, /* Return type */
//                BaseNode,      /* Parent class */
//                nodeTypeID,          /* Name of function in C++ (must match Python name) */
//        );
//    }
//};

//class AddNode : public BaseNode {
//public:
//    int execute() override { return -1; }
//    int nodeTypeID() const override { return 3; }
//};


template< typename T >
static T* creator() { return new T(); }

BaseNode* my_create( std::function< BaseNode*() > func ) {
    return func();
}

//
//class MyManager {
//
//    using CreateFunc = std::function< BaseNode*() >;
//    using NodeMap = std::map< std::string, CreateFunc >;
////    using NodeMap = std::map< std::string, py::object >;
//
//public:
//    MyManager() : m_nodes() { /*add( "add", &createAddNode );*/ }
//    ~MyManager() = default;
//
//    int func_arg(const std::function<int(int)> &f) {
//        return f(10);
//    }
//
//    void add( const std::string& name, CreateFunc func ) {
//        BMO_ERROR << "Adding node: " << name;
//        m_nodes[ name ] = func;
//    }
//
//    std::shared_ptr< BaseNode > create( const std::string& name ) {
//        auto iter = m_nodes.find( name );
//        if ( iter != m_nodes.end() ) {
//            BMO_ERROR << "Found node: " << name;
//            auto creator = iter->second;
//            return std::shared_ptr< BaseNode >( creator() );
//        }
//        return nullptr;
//    }
//
//private:
//    NodeMap m_nodes;
//};

// ---------------------------------------------------------

class BaseA {
public:
    BaseA(int v) : value_(v) {}
    int value() const { return value_; }
private:
    int value_{};
};

std::shared_ptr<BaseA> create_instance() {
    return std::shared_ptr< BaseA >( new BaseA(1) );
}

std::shared_ptr<BaseA> check_creation(py::function py_factory) {
    std::shared_ptr<BaseA> obj;{
        py::object py_obj = py_factory();
        obj = py::cast<std::shared_ptr<BaseA>>(py_obj);
    }
    return obj;
}


class MyManager {

    using CreateFunc = std::function< std::shared_ptr<BaseA>() >;
    using NodeMap = std::map< std::string, CreateFunc >;

public:

    void add( const std::string& name, CreateFunc func ) {
        m_nodes[ name ] = func;
    }

    std::shared_ptr< BaseA > create( const std::string& name ) {
        auto iter = m_nodes.find( name );
        if ( iter != m_nodes.end() ) {
            BMO_ERROR << "Found node: " << name;
            auto creator = iter->second;
            return creator();
        }
        return nullptr;
    }

private:
    NodeMap m_nodes;
};

// ---------------------------------------------------------

PYBIND11_MODULE(pybemo, m) {


    py::class_<BaseA, std::shared_ptr<BaseA>>(m, "BaseA")
            .def(py::init<int>())
            .def("value", &BaseA::value);

    py::class_<BaseNode, std::shared_ptr<BaseNode>>(m, "BaseNode")
            .def(py::init<>())
            .def("execute", &BaseNode::execute);

    m.def("create_instance", &create_instance);
    m.def("check_creation", &check_creation);



    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");
    m.def("create", &my_create);

//    py::class_<BaseNode, PyBaseNode > pyBaseNode(m, "BaseNode");

//    pyBaseNode

    py::class_<MyManager>(m, "MyManager")
            .def(py::init<>())
            .def("add", &MyManager::add)
            .def("create", &MyManager::create);
//                 []( const std::string& n, std::function< BaseNode*() >& f ) {
//                return std::unique_ptr<BaseNode*, py::nodelete >( this->create( n, f ) );
//                }, );


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




