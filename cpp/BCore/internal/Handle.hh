#ifndef BEMO_HANDLE_HH
#define BEMO_HANDLE_HH

#include <climits>
#include <ostream>
#include <BCore/Bemo.hh>
#include <BCore/util/Log.hh>
#include <BCore/internal/Type.hh>

namespace bemo {

template< typename N, std::size_t I, std::size_t V >
class Handle;

template< typename N, std::size_t I, std::size_t V >
std::ostream& operator<<( std::ostream& stream, const Handle< N, I, V >& handle ) {
//    return stream << "Handle(index=" << handle.index() << ", version=" << handle.version() << ")";
    return stream << "Handle(" << handle.index() << ")";
}

template< typename N, std::size_t I, std::size_t V >
class Handle {

    static_assert( std::is_arithmetic< N >::value,
            "NumericType must be numeric" );
    static_assert( sizeof( N ) * CHAR_BIT >= ( V + I ),
            "Invalid handle layout. More bits used than base value type can hold" );

public:

    using NumericType = N;

public:
    static constexpr std::size_t NUM_INDEX_BITS{ I };
    static constexpr std::size_t NUM_VERSION_BITS{ V };
    static constexpr NumericType MIN_INDEX{ 0 };
    static constexpr NumericType MIN_VERSION{ 0 };
    static constexpr NumericType MAX_INDEX{ ( NumericType( 1 ) << NUM_INDEX_BITS ) - 1 };
    static constexpr NumericType MAX_VERSION{ ( NumericType( 1 ) << NUM_VERSION_BITS ) - 1 };
    static constexpr NumericType INVALID_HANDLE{ std::numeric_limits< NumericType >::max() };

public:
    static Handle identity() { return Handle< N, I, V >( 0 ); }
    static Handle invalid() { return Handle< N, I, V >( INVALID_HANDLE, ObjectType::Invalid ); }

public:
    explicit Handle( NumericType id ) : m_id( id ) {}
    Handle( const Handle& rhs ) { this->m_id = rhs.m_id; }
    Handle& operator=( const Handle& rhs ) {
        this->m_id = rhs.m_id;
        return *this;
    }
    bool operator==( const Handle& rhs ) const { return this->m_id == rhs.m_id; }
    bool operator!=( const Handle& rhs ) const { return this->m_id != rhs.m_id; }
    bool operator<( const Handle& rhs ) const { return this->index() < rhs.index(); }
    bool operator>( const Handle& rhs ) const { return this->index() > rhs.index(); }
    NumericType index() const { return m_id & MAX_INDEX; }
    NumericType version() const { return ( m_id >> NUM_INDEX_BITS) & MAX_VERSION; }
    bool isValid() const { return m_id < INVALID_HANDLE; }
    inline operator NumericType() const { return m_id; }

private:
    NumericType m_id;
};

template< typename N, std::size_t I, std::size_t V >
constexpr N Handle< N, I, V >::MIN_INDEX;

template< typename N, std::size_t I, std::size_t V >
constexpr N Handle< N, I, V >::MAX_INDEX;

template< typename N, std::size_t I, std::size_t V >
constexpr N Handle< N, I, V >::MIN_VERSION;

template< typename N, std::size_t I, std::size_t V >
constexpr N Handle< N, I, V >::MAX_VERSION;

}

#endif // BEMO_HANDLE_HH
