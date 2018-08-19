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

    friend class PlugManager;

public:
    explicit Plug( const PlugName& name,
                   PlugType type,
                   PlugDirection direction,
                   bool isRequired,
                   bool isStrict )
                   : m_id(),
                     m_direction( direction ),
                     m_type( type ),
                     m_name( name ) {}
    PlugDirection getDirection() const { return m_direction; }
    PlugType getDataType() const { return m_type; }
    PlugName getName() const { return m_name; }
private:
    ObjectID m_id;
    PlugType m_type;
    PlugName m_name;
    PlugDirection m_direction;

    bool m_isStrict;
    bool m_isRequired;
};

}

#endif // BEMO_PLUG_HH
