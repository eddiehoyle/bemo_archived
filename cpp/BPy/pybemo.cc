
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

class PyAbstractNode : public AbstractNode {
public:
    using AbstractNode::AbstractNode;
    virtual ~PyAbstractNode() = default;
    int execute() override {
        PYBIND11_OVERLOAD(
                int,
                AbstractNode,
                execute,
        );
    }
};

class Animal {
public:
    virtual ~Animal() = default;
    virtual std::string name() { return "unknown"; }
};
class Dog : public Animal {
public:
    virtual std::string bark() { return "woof!"; }
};

class PyAnimal : public Animal {
public:
    using Animal::Animal; // Inherit constructors
    std::string name() override { PYBIND11_OVERLOAD(std::string, Animal, name, ); }
};
class PyDog : public Dog {
public:
    using Dog::Dog; // Inherit constructors
    std::string name() override { PYBIND11_OVERLOAD(std::string, Dog, name, ); }
    std::string bark() override { PYBIND11_OVERLOAD(std::string, Dog, bark, ); }
};
class Husky : public Dog {};
class PyHusky : public Husky {
public:
    using Husky::Husky; // Inherit constructors
    std::string name() override { PYBIND11_OVERLOAD(std::string, Husky, name, ); }
    std::string bark() override { PYBIND11_OVERLOAD(std::string, Husky, bark, ); }
};

//template <class AnimalBase = Animal>
//class PyAnimal : public AnimalBase {
//public:
//    using AnimalBase::AnimalBase; // Inherit constructors
//    std::string go(int n_times) override { PYBIND11_OVERLOAD_PURE(std::string, AnimalBase, go, n_times); }
//    std::string name() override { PYBIND11_OVERLOAD(std::string, AnimalBase, name, ); }
//};
//template <class DogBase = Dog>
//class PyDog : public PyAnimal<DogBase> {
//public:
//    using PyAnimal<DogBase>::PyAnimal; // Inherit constructors
//    // Override PyAnimal's pure virtual go() with a non-pure one:
//    std::string go(int n_times) override { PYBIND11_OVERLOAD(std::string, DogBase, go, n_times); }
//    std::string bark() override { PYBIND11_OVERLOAD(std::string, DogBase, bark, ); }
//};

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
    m.def("create", []( const std::string& type )->AbstractNode*{
        return BMO_NodeManager->create( type );
    });
    m.def("test", []( std::function<Dog*()> func ){
        return func();
    }, py::return_value_policy::reference );
    m.def("test2", []( py::function func ){
        return func();
    }, py::return_value_policy::reference );

    py::class_<AbstractNode, PyAbstractNode>(m, "AbstractNode")
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

    py::class_<Animal, PyAnimal> animal(m, "Animal");
    animal.def(py::init<>()).def("name", &Animal::name);

    py::class_<Dog, PyDog> dog(m, "Dog");
    dog.def(py::init<>()).def("name", &Dog::name);
//    py::class_<Husky, PyDog<Husky>> husky(m, "Husky");
//    husky.def(py::init<>()).def("go", &Husky::go);










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
