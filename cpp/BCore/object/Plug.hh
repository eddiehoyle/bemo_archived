#ifndef BEMO_PLUG_HH
#define BEMO_PLUG_HH

#include <vector>
#include <BCore/internal/Object.hh>
#include <BCore/Variant.hh>

namespace bemo {

enum class PlugDirectionPolicy {
    Input,
    Output,
    Ambiguous,
};

enum class PlugCastPolicy {
    Strict,
    Similar,
    Anything,
};

enum class PlugAccessPolicy {
    Single,
    Multiple,
};

using PlugName = std::string;

class Plug {

    friend class NodeSystem;
    friend class PlugManager;

public:

    static Plug invalid() {
        static Plug plug( "invalid",
                          PlugDirectionPolicy::Ambiguous,
                          PlugAccessPolicy::Single,
                          PlugCastPolicy::Anything,
                          VariantType::Null );
        return plug;
    }

public:
    explicit Plug( const PlugName& name,
                   PlugDirectionPolicy direction,
                   PlugAccessPolicy access,
                   PlugCastPolicy data,
                   VariantType type )
                   : m_id(),
                     m_owner(),
                     m_data(),
                     m_directionPolicy( direction ),
                     m_name( name ),
                     m_accessPolicy( access ),
                     m_dataPolicy( data),
                     m_isRequired( false ) {}

    inline bool isValid() const { return ( m_id != ObjectID() ) && ( m_owner != ObjectID() ); }

    inline ObjectID getID() const { return m_id; }
    inline ObjectID getOwnerID() const { return m_owner; }

    void setValue( const Variant& var ) { m_data.reset( var ); }
    const Variant& getValue() const { return m_data; }

    inline void setMulti( bool state ) { m_multi = state; }
    inline bool isMulti() const { return m_multi; }

    inline void setRequired( bool state ) { m_isRequired = state; }
    inline bool isRequired( bool state ) const { return m_isRequired; }

    inline PlugName getName() const { return m_name; }
    inline VariantType getType() const { return m_type; }

    inline PlugDirectionPolicy getDirection() const { return m_directionPolicy; }
    inline PlugAccessPolicy getAccess() const { return m_accessPolicy; }
    inline PlugCastPolicy getCast() const { return m_dataPolicy; }

private:
    ObjectID m_id;
    ObjectID m_owner;
    Variant m_data;

    /// Supports multiple connections
    bool m_multi;

    std::map< std::size_t, ObjectID > m_connections;

    PlugName m_name;
    VariantType m_type;

    PlugDirectionPolicy m_directionPolicy;
    PlugAccessPolicy m_accessPolicy;
    PlugCastPolicy m_dataPolicy;

    bool m_isRequired;
};

}

#endif // BEMO_PLUG_HH
