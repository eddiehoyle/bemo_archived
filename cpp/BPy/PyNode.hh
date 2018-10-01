#ifndef BEMO_PYABSTRACTNODE_HH
#define BEMO_PYABSTRACTNODE_HH

#include <BCore/managers/NodeManager.hh>
#include <BCore/object/AbstractNode.hh>
#include <BCore/system/PlugSystem.hh>

#include "AbstractProxyObject.hh"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

using namespace bemo;

static py::object castToPy( const Variant& var ) {
    bool result;
    py::object value;
    switch ( var.type() ) {
        case VariantType::Long:
            value = py::int_( var.toLong( &result ) );
            break;
        case VariantType::Float:
            value = py::float_( var.toFloat( &result ) );
            break;
        case VariantType::String:
            value = py::str( var.toString( &result ) );
            break;
        case VariantType::Null:
        default:
            value = py::none();
    }
    return value;
}

static Variant castFromPy( const py::object& obj ) {
    Variant value;
    if ( py::isinstance< py::int_ >( obj ) ) {
        value.reset( Variant( obj.cast< long >() ) );
    } else if ( py::isinstance< py::float_ >( obj ) ) {
        value.reset( Variant( obj.cast< float >() ) );
    } else if ( py::isinstance< py::str >( obj ) ) {
        value.reset( Variant( obj.cast< std::string >() ) );
    } else if ( py::isinstance< py::none >( obj ) ) {
    } else {
    }
    return value;
}

class PyNode;
class PyProxyNode;

typedef std::unique_ptr< PyNode, py::nodelete > PyNodePtr;
typedef std::shared_ptr< PyProxyNode > PyProxyNodePtr;

class PyNode : public AbstractNode {
public:
    using AbstractNode::AbstractNode;
    virtual ~PyNode() { BMO_ERROR << "PyNode dtor=" << (void*)this; }
    int execute() override {
        PYBIND11_OVERLOAD(
                int,
                AbstractNode,
                execute,
        );
    }
};


class PyProxyNode : public AbstractProxyObject {
public:
    using AbstractProxyObject::AbstractProxyObject;
    explicit PyProxyNode( ObjectID id ) : AbstractProxyObject( id ) {}
    virtual ~PyProxyNode() override = default;
};

#endif // BEMO_PYABSTRACTNODE_HH
