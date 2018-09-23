#ifndef BEMO_PYABSTRACTNODE_HH
#define BEMO_PYABSTRACTNODE_HH

#include <BCore/managers/NodeManager.hh>
#include <BCore/object/AbstractNode.hh>
#include <BCore/system/PlugSystem.hh>

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


class PyAbstractNode : public AbstractNode {
public:
    using AbstractNode::AbstractNode;
    void setInput( const std::string& name,
                   const py::object& value ) {
        PlugSystem fnPlug( this->getID() );
        fnPlug.setInput( name, castFromPy( value ) );
    }
    py::object getOutput( const std::string& name ) {
        PlugSystem fnPlug( this->getID() );
        return castToPy( fnPlug.getOutput( name ) );
    }
};


class PyNode : public PyAbstractNode {
public:
    using PyAbstractNode::PyAbstractNode;
    virtual ~PyNode() { BMO_ERROR << "Deleting PyNode"; }
    int execute() override {
        PYBIND11_OVERLOAD(
                int,
                AbstractNode,
                execute,
        );
    }
};


class PyProxyNode : public PyAbstractNode {
public:
    using PyAbstractNode::PyAbstractNode;
    virtual ~PyProxyNode() { BMO_ERROR << "Deleting PyProxyNode"; }
    explicit PyProxyNode( ObjectID id ) : PyAbstractNode() {
        m_id = id;
    }
};

#endif // BEMO_PYABSTRACTNODE_HH
