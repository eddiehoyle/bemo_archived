#ifndef BEMO_PLUG_HH
#define BEMO_PLUG_HH

#include <vector>
#include <BCore/internal/Object.hh>

namespace bemo {

enum class PlugDirection {
    Input,
    Output,
};

enum class PlugType {
    Int,
    String,
    Float,
    List,
    Dict,
    Variant,
};

using PlugName = std::string;

class Plug {

    friend class NodeSystem;
    friend class PlugManager;

public:
    explicit Plug( const PlugName& name,
                   PlugDirection direction,
                   PlugType type )
                   : m_id(),
                     m_owner(),
                     m_data(),
                     m_direction( direction ),
                     m_type( type ),
                     m_name( name ),
                     m_isStrict( false ),
                     m_isRequired( false ) {}

    inline bool isValid() const { return ( m_id != ObjectID() ) && ( m_owner != ObjectID() ); }
    inline void setStrict( bool state ) { m_isStrict = state; }
    inline void setRequired( bool state ) { m_isRequired = state; }

    inline PlugName getName() const { return m_name; }
    inline PlugDirection getDirection() const { return m_direction; }
    inline PlugType getType() const { return m_type; }

    void connect() {}
    void disconnect() {}
    bool isConnected() const { return false; }

private:
    ObjectID m_id;
    ObjectID m_owner;
    ObjectID m_data;

    PlugName m_name;
    PlugDirection m_direction;
    PlugType m_type;

    bool m_isStrict;
    bool m_isRequired;
};

}

#endif // BEMO_PLUG_HH
