
#include <pybind11/stl.h>

#include <Node.hh>
#include <Graph.hh>

namespace py = pybind11;
using namespace bemo;

class Child {};

class Parent {
public:
    Parent() : child( std::make_shared<Child>()) { }
    std::shared_ptr<Child> get_child() { return child; }
private:
    std::shared_ptr<Child> child;
};

PYBIND11_MODULE(pybemo, m) {

    py::class_<Node, std::shared_ptr<Node> >(m, "Node")
            .def(py::init<const std::string &>())
            .def("set_name", &Node::set_name)
            .def("get_name", &Node::get_name)
            .def("execute", &Node::execute)
            .def("__repr__",
                 [](const Node &a) {
                     return "<pybemo.Node '" + a.get_name() + "'>";
                 }
            );

    py::class_<Graph, std::shared_ptr<Graph> >(m, "Graph")
            .def(py::init<>())
            .def("add", &Graph::add)
            .def("remove", &Graph::remove)
            .def("get_count", &Graph::get_count)
            .def("execute", &Graph::execute)
            .def("__repr__",
                 [](const Graph &g) {
                     return "<pybemo.Graph count=" + std::to_string( g.get_count() ) + ">";
                 }
            );

    m.def("create_node", &create_node, py::arg("name"));
    m.def("read_node", &read_node, py::arg("node"));

//    py::class_<Child, std::shared_ptr<Child>>(m, "Child");
//
//    py::class_<Parent, std::shared_ptr<Parent>>(m, "Parent")
//            .def(py::init<>())
//            .def("get_child", &Parent::get_child);

}




