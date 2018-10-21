#ifndef BEMO_BLUEPRINTMANAGER_HH
#define BEMO_BLUEPRINTMANAGER_HH

#include <BCore/object/Object.hh>
#include <BCore/object/ObjectID.hh>
#include <map>

namespace bemo {

//
//template< typename F >
//class FuncWrapper {
//public:
//    explicit FuncWrapper( F func ) : m_func( func ) {}
//    ~FuncWrapper() = default;
//    F get() const { return m_func; }
//private:
//    F m_func;
//};
//
//class Blueprint {
//public:
//    explicit Blueprint( FuncWrapper* wrapper ) : m_
//};
//

class AbstractBlueprint {
public:
    virtual ~AbstractBlueprint() = default;
    virtual void* getCreate() = 0;
};

template< typename C >
class Blueprint : public AbstractBlueprint {
public:
    typedef C create_type;
    Blueprint( std::function< C() > fnCreate ) : m_create( fnCreate ) {}
    void* getCreate() { return static_cast< void* >( &m_create ); }
private:
    std::function< C() > m_create;

};

class BlueprintManager {
public:
    static BlueprintManager& instance();

public:
    BlueprintManager( BlueprintManager const& ) = delete;

    void operator=( BlueprintManager const& ) = delete;

    template< typename C >
    void add( const std::string& type, std::function< C() > wrCreate ) {
        BMO_ERROR << "Adding blueprint=" << type;
        m_blueprints[type] = new Blueprint<C>( wrCreate );
    }

    AbstractBlueprint* get( const std::string& type ) const {
        auto iter = m_blueprints.find( type );
        if ( iter != m_blueprints.end() ) {
            return iter->second;
        }
        return nullptr;
    }


private:
    BlueprintManager() {}

    std::map< std::string, AbstractBlueprint* > m_blueprints;
};

}


#endif // BEMO_BLUEPRINTMANAGER_HH
