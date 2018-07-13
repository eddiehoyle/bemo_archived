#ifndef BEMO_HANDLE_HH
#define BEMO_HANDLE_HH

namespace bemo {

template< typename ValueType,
        std::size_t IndexBits,
        std::size_t VersionBits >
class Handle {

    static_assert( sizeof( ValueType ) * CHAR_BIT >= ( VersionBits + IndexBits ),
                   "Invalid handle layout. More bits used than base value type can hold!" );
public:

    static constexpr std::size_t NUM_INDEX_BITS { IndexBits };
    static constexpr std::size_t NUM_VERSION_BITS { VersionBits };

    static constexpr ValueType MAX_INDICES { (1U << NUM_INDEX_BITS)   - 2U };
    static constexpr ValueType MIN_VERISON { 0 };
    static constexpr ValueType MAX_VERSION { (1U << NUM_VERSION_BITS) - 2U };
    static constexpr ValueType INVALID_HANDLE { std::numeric_limits< ValueType >::max() };

public:
    Handle() : m_id( 0 ) {}
    Handle& operator=( const Handle& rhs ) { this->m_id = rhs.m_id; }
    ValueType index() const { return m_id & MAX_INDICES; }
    ValueType version() const { return ( m_id >> NUM_INDEX_BITS) & MAX_VERSION; }
    inline operator ValueType() const { return m_id; }

private:
    ValueType m_id;
};

}

#endif // BEMO_HANDLE_HH
