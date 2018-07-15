#ifndef BEMO_TABLE_HH
#define BEMO_TABLE_HH

#include <cstddef>
#include <utility>
#include <list>
#include <deque>
#include <vector>
#include <array>

#include "Handle.hh"

namespace bemo {

template< typename T, typename H >
class HandleTable {

    using Handle = H;

public:
    HandleTable()
        : m_indices(),
          m_versions(),
          m_objects() {}
    ~HandleTable() = default;

    Handle acquire( T* object ) {
        auto iter = std::find( m_indices.begin(), m_indices.end(),
                               typename Handle::NumericType( Handle::INVALID_HANDLE ) );
        if ( iter != m_indices.end() ) {
            typename Handle::NumericType index = std::distance( m_indices.begin(), iter );
            m_indices[ index ] = index;
            m_objects[ index ] = object;
            return Handle( index | m_versions[ index ] << Handle::NUM_INDEX_BITS );
        }
        return Handle( Handle::INVALID_HANDLE );
    }

    void release( Handle handle ) {
        if ( !isExpired( handle ) ) {
            m_versions[handle.index()] = ( m_versions[handle.index()] + 1 > Handle::MAX_VERSION )
                    ? Handle::MIN_VERSION
                    : m_versions[handle.index()] + 1;
            m_indices[handle.index()] = Handle::INVALID_HANDLE;
            m_objects[handle.index()] = nullptr;
        }
    }

    bool isExpired( Handle handle ) {
        return m_versions[ handle.index() ] != handle.version();
    }

    inline Handle operator[]( typename Handle::NumericType index ) const {
        return Handle( index | m_versions[ index ] << Handle::NUM_INDEX_BITS );
    }

    inline T* operator[]( Handle handle ) {
        return m_objects[ handle.index() ];
    }

private:
    std::vector< typename Handle::NumericType > m_indices;
    std::vector< typename Handle::NumericType > m_versions;
    std::vector< T* > m_objects;

};

}

#endif // BEMO_TABLE_HH
