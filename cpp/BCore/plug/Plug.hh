#ifndef BEMO_PLUG_HH
#define BEMO_PLUG_HH

#include "AbstractPlug.hh"

namespace bemo {

template< typename P >
class Plug : public AbstractPlug {
public:
    static const PlugTypeID TYPEID;
protected:
    explicit Plug( PlugID id ) : AbstractPlug( id ) {}
    ~Plug() override = default;
private:
};

template< typename P >
const bemo::PlugTypeID Plug< P >::TYPEID =
        bemo::internal::ObjectTypeID< bemo::AbstractPlug >::allocate< P >();

} // namespace bemo

#endif // BEMO_PLUG_HH
