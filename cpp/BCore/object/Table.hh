#ifndef BEMO_TABLE_HH
#define BEMO_TABLE_HH

//#include <cstddef>
//#include <utility>
//#include <list>
#include <deque>
//#include <vector>
//#include <array>
//#include <map>

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
        if ( exists( handle ) ) {

            // Check bounds
            typename Handle::NumericType version = m_versions[handle.index()];
            if ( version + 1 < Handle::MAX_VERSION ) {
                ++version;
            } else {
                version = Handle::MIN_VERSION;
            }

            // Increment
            m_versions[ handle.index() ] = version;
        }
    }

    bool exists( Handle handle ) {
        return ( handle.index() < m_versions.size() )
                ? m_versions[ handle.index() ] == handle.version()
                : false;
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
