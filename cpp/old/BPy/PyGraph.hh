#ifndef BEMO_PYABSTRACTGRAPH_HH
#define BEMO_PYABSTRACTGRAPH_HH


#include <old/BCore/managers/NodeManager.hh>
#include <old/BCore/object/AbstractNode.hh>
#include <old/BCore/object/AbstractGraph.hh>
#include <old/BCore/system/PlugSystem.hh>

#include "AbstractProxyObject.hh"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

using namespace bemo;

class PyGraph;
class PyProxyGraph;

typedef std::unique_ptr< PyGraph, py::nodelete > PyGraphPtr;
typedef std::shared_ptr< PyProxyGraph > PyProxyGraphPtr;


class PyGraph : public AbstractGraph {
public:
    using AbstractGraph::AbstractGraph;
    virtual ~PyGraph() = default;
    void expand() override {
        PYBIND11_OVERLOAD(
                void,
                AbstractGraph,
                expand,
        );
    }
};

class PyProxyGraph : public AbstractProxyObject {
public:
    using AbstractProxyObject::AbstractProxyObject;
    explicit PyProxyGraph( ObjectID id ) : AbstractProxyObject( id ) {}
    ~PyProxyGraph() override = default;
};


#endif // BEMO_PYABSTRACTGRAPH_HH
