#ifndef BEMO_NODEREGISTRY_HH
#define BEMO_NODEREGISTRY_HH

#include <map>
#include <functional>

namespace bemo {

class AbstractNode;

using CreatorFunc = std::function< AbstractNode*() >;

class NodeRegistry {

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
#endif // BEMO_NODEREGISTRY_HH
