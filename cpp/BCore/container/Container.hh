#ifndef BEMO_CONTAINER_HH
#define BEMO_CONTAINER_HH

#include "AbstractContainer.hh"
#include <BCore/internal/ObjectType.hh>

namespace bemo {

template< typename C >
class Container : public AbstractContainer {
public:
    static const ContainerTypeID TYPEID;
protected:

    explicit Container( ContainerID id ) : AbstractContainer( id ) {}
    ~Container() override = default;

    virtual void getInput( void* ) const {}
    virtual void getOutput( void* ) const {}

    virtual void getInputs() const {}
    virtual void getOutputs() const {}

    virtual void getConnections() const {}

    int execute() override { return 0; } ;

private:
};

template< typename C >
const bemo::ContainerID Container< C >::TYPEID =
        bemo::internal::ObjectTypeID< bemo::AbstractContainer >::allocate<C>();

}

#endif // BEMO_CONTAINER_HH