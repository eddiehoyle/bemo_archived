#ifndef BEMO_PYPROXYOBJECT_HH
#define BEMO_PYPROXYOBJECT_HH

#include <old/BCore/internal/Object.hh>
#include <memory>

#include "AbstractProxyObject.hh"

using namespace bemo;

class AbstractProxyObject {
public:
    explicit AbstractProxyObject( ObjectID id ) : m_id( id ) {}
    virtual ~AbstractProxyObject() = default;
    ObjectID getID() const { return m_id; }
private:
    ObjectID m_id;
};


#endif // BEMO_PYPROXYOBJECT_HH
