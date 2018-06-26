
#include <pybind11/stl.h>

#include <Node.hh>
#include <Graph.hh>

namespace py = pybind11;
using namespace bemo;

PYBIND11_MODULE(pybemo, m) {

    py::class_<Node>(m, "Node")
            .def(py::init<const std::string &>())
            .def("set_name", &Node::set_name)
            .def("get_name", &Node::get_name)
            .def("__repr__",
                 [](const Node &a) {
                     return "<pybemo.Node '" + a.get_name() + "'>";
                 }
            );

    py::class_<Graph>(m, "Graph")
            .def(py::init<>())
            .def("add", &Graph::add)
            .def("remove", &Graph::remove)
            .def("get_count", &Graph::get_count)
            .def("__repr__",
                 [](const Graph &g) {
                     return "<pybemo.Graph count=" + std::to_string( g.get_count() ) + ">";
                 }
            );

    m.def("create_node", &create_node, py::arg("name"));
    m.def("read_node", &read_node, py::arg("node"));

}




