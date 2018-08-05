#ifndef BEMO_PYNODEREGISTRY_HH
#define BEMO_PYNODEREGISTRY_HH

#include <pybind11/pybind11.h>

#include <functional>
#include <map>

namespace py = pybind11;

namespace bemo {

using CreatorFunc = std::function< py::object() >;
using InitFunc = std::function< py::object( py::object ) >;

class PyNodeRegistry {

    using CreatorMap = std::map< std::string, CreatorFunc >;
    using InitMap = std::map< std::string, InitFunc >;

public:
    void add( const std::string& type, CreatorFunc& creFunc, InitFunc& iniFunc ) {
        m_creators[ type ] = std::move( creFunc );
        m_initialisers[ type ] = std::move( iniFunc );
    }
    CreatorFunc findCreator( const std::string& type ) const {
        auto iter = m_creators.find( type );
        if ( iter != m_creators.end() ) {
            return iter->second;
        }
        return CreatorFunc( py::none() );
    }

    InitFunc findInitialiser( const std::string& type ) const {
        auto iter = m_initialisers.find( type );
        if ( iter != m_initialisers.end() ) {
            return iter->second;
        }
        return InitFunc( nullptr );
    }

private:
    CreatorMap m_creators;
    InitMap m_initialisers;
};

}

#endif // BEMO_PYNODEREGISTRY_HH
