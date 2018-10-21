#include "BlueprintManager.hh"

namespace bemo {

BlueprintManager& BlueprintManager::instance() {
    static BlueprintManager mgr;
    return mgr;
}
//
//template< typename C, typename L >
//void BlueprintManager::add( const std::string& type,
//                            C wrCreate,
//                            L wrLayout ) {
//    Blueprint* blueprint = new Blueprint<C, L>( wrCreate, wrLayout );
//
//}

//}

}