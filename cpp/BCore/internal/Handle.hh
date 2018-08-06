#ifndef BEMO_HANDLE_HH
#define BEMO_HANDLE_HH

#include <BCore/util/Log.hh>
#include <climits>
#include <ostream>
#include <BCore/API.hh>

namespace bemo {


template< ObjectType T, typename N, std::size_t I, std::size_t V >
class Handle;

template< ObjectType T, typename N, std::size_t I, std::size_t V >
std::ostream& operator<<( std::ostream& stream, const Handle< T, N, I, V >& handle ) {
    return stream << "Handle(index=" << handle.index() << ", version=" << handle.version() << ")";
}

template< ObjectType T, typename N, std::size_t I, std::size_t V >
class Handle {

    static_assert(std::is_arithmetic< N >::value, "NumericType must be numeric");
    static_assert( sizeof( N ) * CHAR_BIT >= ( V + I ),
                   "Invalid handle layout. More bits used than base value type can hold" );

public:

    using NumericType = N;

public:
    static constexpr std::size_t NUM_INDEX_BITS{ I };
    static constexpr std::size_t NUM_VERSION_BITS{ V };
    static constexpr NumericType MIN_INDEX{ 0 };
    static constexpr NumericType MAX_INDICES{ ( NumericType( 1 ) << NUM_INDEX_BITS ) - 1 };
    static constexpr NumericType MIN_VERSION{ 0 };
    static constexpr NumericType MAX_VERSION{ ( NumericType( 1 ) << NUM_VERSION_BITS ) - 1 };
    static constexpr NumericType INVALID_HANDLE{ std::numeric_limits< NumericType >::max() };

public:
    static Handle identity() { return Handle< T, N, I, V >( 0, T ); }
    static Handle invalid() { return Handle< T, N, I, V >( INVALID_HANDLE, ObjectType::Invalid ); }

public:
    explicit Handle( NumericType id ) : m_type( T ), m_id( id ) {}
    Handle( const Handle& rhs ) { this->m_id = rhs.m_id; this->m_type = rhs.m_type; }
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
    ObjectType m_type;
};

template< ObjectType T, typename N, std::size_t I, std::size_t V >
constexpr N Handle< T, N, I, V >::MIN_INDEX;

template< ObjectType T, typename N, std::size_t I, std::size_t V >
constexpr N Handle< T, N, I, V >::MAX_INDICES;

template< ObjectType T, typename N, std::size_t I, std::size_t V >
constexpr N Handle< T, N, I, V >::MIN_VERSION;

template< ObjectType T, typename N, std::size_t I, std::size_t V >
constexpr N Handle< T, N, I, V >::MAX_VERSION;

}

#endif // BEMO_HANDLE_HH
