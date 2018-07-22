#ifndef BEMO_NODEREGISTRY_HH
#define BEMO_NODEREGISTRY_HH

namespace bemo {

class NodeRegistry {

    typedef void( C::*Func )();

    template< typename C >
    class AbstractDelegate {};

public:
    void add( TypeID nodeTypeID,
              std::function<void>& create,
              std::function<void>& header,
              std::function<void>& layout ) {}
private:
    std::map< TypeID, std::vector< Func > > m_functions;
};
}
#endif // BEMO_NODEREGISTRY_HH
