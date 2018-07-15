#ifndef BEMO_HANDLE_HH
#define BEMO_HANDLE_HH

#include <BCore/util/Log.hh>

namespace bemo {

template< typename N,
        std::size_t IndexBits,
        std::size_t VersionBits >
class Handle {

public:
    using NumericType = N;

    static_assert(std::is_arithmetic< NumericType >::value, "NumericType must be numeric");
    static_assert( sizeof( NumericType ) * CHAR_BIT >= ( VersionBits + IndexBits ),
                   "Invalid handle layout. More bits used than base value type can hold" );

public:
    static constexpr std::size_t NUM_INDEX_BITS{ IndexBits };
    static constexpr std::size_t NUM_VERSION_BITS{ VersionBits };

    static constexpr NumericType MIN_INDEX{ 0 };
    static constexpr NumericType MAX_INDICES{ ( NumericType( 1 ) << NUM_INDEX_BITS ) - 1 };
    static constexpr NumericType MIN_VERSION{ 0 };
    static constexpr NumericType MAX_VERSION{ ( NumericType( 1 ) << NUM_VERSION_BITS ) - 1 };

    static constexpr NumericType INVALID_HANDLE{ std::numeric_limits< NumericType >::max() };

public:
    Handle() : m_id( 0 ) {}
    explicit Handle( NumericType id ) : m_id( id ) {}
    Handle( const Handle& rhs ) { this->m_id = rhs.m_id; }
    Handle& operator=( const Handle& rhs ) { this->m_id = rhs.m_id; }
    bool operator==( const Handle& rhs ) { return this->m_id == rhs.m_id; }
    bool operator!=( const Handle& rhs ) { return this->m_id != rhs.m_id; }
    bool operator<( const Handle& rhs ) { return this->m_id < rhs.m_id; }
    bool operator>( const Handle& rhs ) { return this->m_id > rhs.m_id; }
    NumericType index() const { return m_id & MAX_INDICES; }
    NumericType version() const { return ( m_id >> NUM_INDEX_BITS) & MAX_VERSION; }
    bool isValid() const { return m_id < INVALID_HANDLE; }
    inline operator NumericType() const { return m_id; }

private:
    NumericType m_id;
};

template< typename N, std::size_t IndexBits, std::size_t VersionBits >
constexpr N Handle< N, IndexBits, VersionBits >::MIN_INDEX;

template< typename N, std::size_t IndexBits, std::size_t VersionBits >
constexpr N Handle< N, IndexBits, VersionBits >::MAX_INDICES;

template< typename N, std::size_t IndexBits, std::size_t VersionBits >
constexpr N Handle< N, IndexBits, VersionBits >::MIN_VERSION;

template< typename N, std::size_t IndexBits, std::size_t VersionBits >
constexpr N Handle< N, IndexBits, VersionBits >::MAX_VERSION;

}

#endif // BEMO_HANDLE_HH
