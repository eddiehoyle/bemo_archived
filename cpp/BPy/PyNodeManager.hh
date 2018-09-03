#ifndef BEMO_PYNODEMANAGER_HH
#define BEMO_PYNODEMANAGER_HH

#include <BCore/managers/NodeManager.hh>

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace py = pybind11;

namespace bemo {

//using FnCreate = std::function< py::object() >;
//using FnLayout = std::function< py::object( ObjectID ) >;

//class PyNodeManager {
//
//    using FnCreateMap = std::map< std::string, FnCreate >;
//    using FnLayoutMap = std::map< std::string, FnLayout >;
//
//public:
//
//    py::object create( const std::string& type ) {
//
//        py::object node = py::none();
//
//        FnCreate fnCreate;
//        FnLayout fnLayout;
//        if ( findBlueprint( type, &fnCreate, &fnLayout ) ) {
//            node = fnCreate();
//            ObjectID id = BMO_ObjectManager()->acquire( ObjectType::Node );
//            fnLayout( id );
//        }
//
//        return node;
//    }
//
//    bool findBlueprint( const std::string& type,
//                        FnCreate* fnCreate,
//                        FnLayout* fnLayout ) {
//
//        bool result = false;
//
//        auto fnCreateIter = m_create.find( type );
//        auto fnLayoutIter = m_layout.find( type );
//        if ( ( fnCreateIter != m_create.end() ) &&
//             ( fnLayoutIter != m_layout.end() ) ) {
//            *fnCreate = fnCreateIter->second;
//            *fnLayout = fnLayoutIter->second;
//            result = true;
//        }
//        return result;
//    }
//
//    void addBlueprint( const std::string& type,
//                       FnCreate& fnCreate,
//                       FnLayout& fnLayout ) {
//        m_create[ type ] = std::move( fnCreate );
//        m_layout[ type ] = std::move( fnLayout );
//    }
//
//private:
//    FnCreateMap m_create;
//    FnLayoutMap m_layout;
//
//};

}

#endif // BEMO_PYNODEMANAGER_HH
