#ifndef BEMO_ABSTRACTPLUG_HH
#define BEMO_ABSTRACTPLUG_HH

#include <BCore/Platform.hh>
#include <BCore/internal/ObjectType.hh>

namespace bemo {

class PlugManager;

using PlugID = ObjectID;
using PlugTypeID = TypeID;

class AbstractPlug {

    friend class PlugManager;

public:
    PlugID id() const { return m_id; }
protected:
    explicit AbstractPlug( PlugID id ) : m_id( id ), m_manager( nullptr ) {}
    virtual ~AbstractPlug() = default;
protected:
    PlugID m_id;
    PlugManager* m_manager;
};

}

#endif // BEMO_PLUG_HH
