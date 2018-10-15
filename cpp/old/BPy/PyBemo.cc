
#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include <old/BCore/Bemo.hh>
#include <old/BCore/util/Log.hh>
#include <old/BCore/managers/NodeManager.hh>
#include <old/BCore/system/NodeSystem.hh>
#include <old/BCore/object/Plugin.hh>

#include <memory>
#include <sstream>
#include <string>
#include <list>

namespace py = pybind11;
using namespace bemo;

void py_genAPI( py::module & );
void py_genEnum( py::module & );
void py_genpNode( py::module & );
void py_genPlug( py::module & );
void py_genSystem( py::module & );

PYBIND11_MODULE(pybemo, m) {

    py_genAPI( m );
    py_genEnum( m );
    py_genNode( m );
    py_genPlug( m );
    py_genSystem( m );


}

