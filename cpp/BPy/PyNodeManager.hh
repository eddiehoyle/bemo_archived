#ifndef BEMO_PYNODEMANAGER_HH
#define BEMO_PYNODEMANAGER_HH

#include "pybemo.hh"
#include "PyNodeRegistry.hh"

#include <BCore/managers/NodeManager.hh>

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace py = pybind11;

namespace bemo {

class PyNodeManager : public NodeManager {
public:
    py::object create( const std::string& type ) {
        CreatorFunc creFunc = BMO_PyNodeRegistry->findCreator( type );
        InitFunc initFunc = BMO_PyNodeRegistry->findInitialiser( type );

        py::object node = creFunc();
        acquire( type, node.cast< AbstractNode* >() );

        initFunc( node );

        return node;
    }
};

}

#endif // BEMO_PYNODEMANAGER_HH
