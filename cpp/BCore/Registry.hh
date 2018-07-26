#ifndef BEMO_REGISTRY_HH
#define BEMO_REGISTRY_HH

#include <BCore/object/Node.hh>

namespace bemo {

//class AbstractRegistry {};
//
//template< typename T >
//class Registry : public AbstractRegistry {
//
//};
//
//class NodeRegistry : public Registry< Node >{
//
//    using NodeName = std::string;
//
//public:
//    Node create( const std::string& name ) { return Node( ObjectID::invalid() ); }
//    void release( const std::string& name ) { }
//
//private:
//    std::map< NodeName, std::function<void> > m_createMap;
//    std::map< NodeName, std::function<void> > m_initialiseMap;
//};

}

#endif // BEMO_REGISTRY_HH
