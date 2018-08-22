#ifndef BEMO_PLUG_HH
#define BEMO_PLUG_HH

#include <vector>
#include <BCore/internal/Object.hh>
#include <BCore/Variant.hh>

namespace bemo {

enum class PlugDirection {
    Input,
    Output,
};

using PlugName = std::string;

class Plug {

    friend class NodeSystem;
    friend class PlugManager;

public:
    explicit Plug( const PlugName& name,
                   PlugDirection direction,
                   VariantType type )
                   : m_id(),
                     m_owner(),
                     m_data( 0 ),
                     m_direction( direction ),
                     m_name( name ),
                     m_isStrict( false ),
                     m_isRequired( false ) {}

    inline ObjectID getID() const { return m_id; }
    inline ObjectID getOwnerID() const { return m_owner; }
    const Variant& getData() const { return m_data; }

    inline bool isValid() const { return ( m_id != ObjectID() ) && ( m_owner != ObjectID() ); }
    inline void setStrict( bool state ) { m_isStrict = state; }
    inline void setRequired( bool state ) { m_isRequired = state; }

    inline PlugName getName() const { return m_name; }
    inline PlugDirection getDirection() const { return m_direction; }
    inline VariantType getType() const { return m_type; }

    void connect() {}
    void disconnect() {}
    bool isConnected() const { return false; }

private:
    ObjectID m_id;
    ObjectID m_owner;
    Variant m_data;

    PlugName m_name;
    PlugDirection m_direction;
    VariantType m_type;

    bool m_isStrict;
    bool m_isRequired;
};

}

#endif // BEMO_PLUG_HH
