
#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include <BCore/API.hh>
#include <BCore/util/Log.hh>
#include <BCore/managers/NodeManager.hh>
#include <BCore/system/NodeSystem.hh>
#include <BCore/object/Plugin.hh>

#include <memory>
#include <sstream>
#include <string>
#include <list>

namespace py = pybind11;
using namespace bemo;

void py_genAPI( py::module & );
void py_genEnum( py::module & );
void py_genNode( py::module & );
void py_genSystem( py::module & );

PYBIND11_MODULE(pybemo, m) {

    py_genAPI( m );
    py_genEnum( m );
    py_genNode( m );
    py_genSystem( m );


}

