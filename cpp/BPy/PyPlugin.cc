#include <pybind11/stl.h>
#include <pybind11/eval.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

#include <BCore/object/ObjectID.hh>
#include <BCore/plugin/PluginSystem.hh>

#include <memory>
#include <sstream>
#include <string>
#include <list>
//
//namespace py = pybind11;
//using namespace bemo;
//
//using FnCreate = std::function< py::object() >;
//using FnLayout = std::function< void( py::object ) >;
//
//namespace bemo {
//
////template<>
////Object* CreateFuncWrapper< FnCreate >::invoke() {
////    return m_func();
////}
////
////template<>
////void LayoutFuncWrapper< FnLayout >::invoke( ObjectID id ) {
////    m_func( id );
////}
//
//// Goal:
//// Be able to register a 'create' function in PluginManager
//// and have it create either a Graph or a Node
//
//template <>
//std::shared_ptr< BPyDagNode > CreateFuncWrapper< FnCreate >::invoke() {
//    return py::cast< std::shared_ptr< BPyDagNode >( m_func() );
//}
//
//}
//
//
//
//void py_genPluginSystem( py::module& m ) {
//
//    py::class_< PyPluginSystem, std::shared_ptr< PyPluginSystem > >( m, "PluginSystem" )
//            .def( py::init< ObjectID >() )
//            .def( "setHeader", &PluginSystem::setHeader )
//            .def( "registerNode", &PluginSystem::registerNode );
//}