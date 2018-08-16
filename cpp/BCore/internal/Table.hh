#ifndef BEMO_TABLE_HH
#define BEMO_TABLE_HH

#include <cstddef>
#include <utility>
#include <list>
#include <deque>
#include <vector>
#include <array>
#include <map>

#include "Handle.hh"

namespace bemo {

template< typename H >
class HandleTable {

    using Handle = H;

public:

    Handle acquire() {

        typename Handle::NumericType index = 0;
        if ( m_indices.size() >= Handle::MAX_INDEX ) {

            // Re-use first index
            index = m_indices.front();
            m_indices.pop_front();
            m_indices.push_back( index );

        } else {

            // Create an index
            m_versions.push_back( 0 );
            index = m_versions.size() - 1;
            m_indices.push_back( index );
        }

        return Handle( index | m_versions[index] << Handle::NUM_INDEX_BITS );
    }

    void release( Handle handle ) {
        if ( !isExpired( handle ) ) {
            m_versions[handle.index()] = ( m_versions[handle.index()] + 1 > Handle::MAX_VERSION )
                    ? Handle::MIN_VERSION
                    : m_versions[handle.index()] + 1;
        }
    }

    bool isExpired( Handle handle ) {
        return m_versions[ handle.index() ] != handle.version();
    }

    std::size_t count() const {
        return m_indices.size();
    }

private:
    std::deque< typename Handle::NumericType > m_indices;
    std::vector< typename Handle::NumericType > m_versions;

};

}

#endif // BEMO_TABLE_HH
