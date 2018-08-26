#ifndef BEMO_PLUG_HH
#define BEMO_PLUG_HH

#include <vector>
#include <BCore/internal/Object.hh>
#include <BCore/Variant.hh>

namespace bemo {

enum class PlugDirection {
    Input,
    Output,
    Ambiguous,
};

using PlugName = std::string;

class Plug {

    friend class NodeSystem;
    friend class PlugManager;

public:

    static Plug invalid() {
        static Plug plug( "invalid",
                          PlugDirection::Ambiguous,
                          VariantType::Null );
        return plug;
    }

public:
    explicit Plug( const PlugName& name,
                   PlugDirection direction,
                   VariantType type )
                   : m_id(),
                     m_owner(),
                     m_data(),
                     m_direction( direction ),
                     m_name( name ),
                     m_isStrict( false ),
                     m_isRequired( false ) {}

    inline bool isValid() const { return ( m_id != ObjectID() ) && ( m_owner != ObjectID() ); }

    inline ObjectID getID() const { return m_id; }
    inline ObjectID getOwnerID() const { return m_owner; }

    void setValue( const Variant& var ) { m_data.reset( var ); }
    const Variant& getValue() const { return m_data; }

    inline void setMulti( bool state ) { m_multi = state; }
    inline bool isMulti() const { return m_multi; }

    inline void setStrict( bool state ) { m_isStrict = state; }
    inline bool isStrict() const { return m_isStrict; }

    inline void setRequired( bool state ) { m_isRequired = state; }
    inline bool isRequired( bool state ) const { return m_isRequired; }

    inline PlugName getName() const { return m_name; }
    inline PlugDirection getDirection() const { return m_direction; }
    inline VariantType getType() const { return m_type; }

private:
    ObjectID m_id;
    ObjectID m_owner;
    Variant m_data;

    /// Supports multiple connections
    bool m_multi;

    std::map< std::size_t, ObjectID > m_connections;

    PlugName m_name;
    PlugDirection m_direction;
    VariantType m_type;

    bool m_isStrict;
    bool m_isRequired;
};

}

#endif // BEMO_PLUG_HH
