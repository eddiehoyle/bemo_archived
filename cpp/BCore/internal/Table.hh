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
    HandleTable() = default;
    ~HandleTable() = default;

    Handle acquire( T* object ) {

        typename Handle::NumericType index = 0;
        if ( m_indices.size() >= Handle::MAX_INDICES ) {
            index = m_indices.front();
            m_indices.pop_front();
        } else {
            m_versions.push_back( 0 );
            index = m_versions.size() - 1;
            m_indices.push_back( index );
        }

        m_objects[ index ] = object;

        return Handle( index | m_versions[index] << Handle::NUM_INDEX_BITS );
    }

    void release( Handle handle ) {
        if ( !isExpired( handle ) ) {
            m_versions[handle.index()] = ( m_versions[handle.index()] + 1 > Handle::MAX_VERSION )
                    ? Handle::MIN_VERSION
                    : m_versions[handle.index()] + 1;
            m_indices.push_back( handle.index() );
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
    std::deque< typename Handle::NumericType > m_indices;
    std::vector< typename Handle::NumericType > m_versions;
    std::map< typename Handle::NumericType, T* > m_objects;

};

}

#endif // BEMO_TABLE_HH
