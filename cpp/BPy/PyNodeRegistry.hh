#ifndef BEMO_PYNODEREGISTRY_HH
#define BEMO_PYNODEREGISTRY_HH

#include <pybind11/pybind11.h>

#include <functional>
#include <map>

namespace py = pybind11;

namespace bemo {

using CreatorFunc = std::function< py::object() >;

class PyNodeRegistry {

    using CreatorMap = std::map< std::string, CreatorFunc >;

public:
    void add( const std::string& type, CreatorFunc func ) {
        m_creators[ type ] = func;
    }
    CreatorFunc find( const std::string& type ) const {
        auto iter = m_creators.find( type );
        if ( iter != m_creators.end() ) {
            return iter->second;
        }
        return CreatorFunc( nullptr );
    }

private:
    CreatorMap m_creators;
};

}

#endif // BEMO_PYNODEREGISTRY_HH
