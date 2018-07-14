#ifndef BEMO_TABLE_HH
#define BEMO_TABLE_HH

#include <cstddef>
#include <utility>
#include <list>
#include <deque>
#include <vector>

namespace bemo {

template< typename T, typename H >
class HandleTable {

    using Handle = H;
    using TableEntry = std::pair< typename Handle::NumericType, T* >;

public:
    HandleTable() = default;
    ~HandleTable() = default;

    Handle acquire( T* object ) {

        typename Handle::NumericType id = 0;
        if ( m_indices.size() >= Handle::MAX_INDICES ) {
            id = m_indices.front();
            m_indices.pop_front();
        }
        else {
            m_versions.push_back( 0 );
            id = static_cast< Handle::NumericType >( m_versions.size() - 1 );
            assert(id < ( 1 << Handle::NUM_INDEX_BITS )); /// If maximum amount of Entities has exceeded
        }

        return Handle( m_versions[ id ] << Handle::NUM_INDEX_BITS );
//        e.id |= _generation[e.id] << ENTITY_INDEX_BITS;
//        return e;
//        for ( std::size_t i = 0; i < m_list.size(); ++i ) {
//            if ( m_list[ i ].second == nullptr ) {
//
//                m_list[ i ].second = object;
//
//
//                bool isMaxVersion = ( m_list[ i ].first + 1 ) > Handle::MAX_VERSION;
//                typename Handle::NumericType index = isMaxVersion
//                        ? Handle::MIN_VERISON
//                        : m_list[ i ].first + 1;
//                m_list[ i ].first =  index;
//            }
//        }
//
//        typename Handle::value_type i = 0;
//        for (; i < this->m_Table.size(); ++i) {
//            if (this->m_Table[i].second == nullptr) {
//                this->m_Table[i].second = rawObject;
//                this->m_Table[i].first = ((this->m_Table[i].first + 1) > Handle::MAX_VERSION) ? Handle::MIN_VERISON : this->m_Table[i].first + 1;
//                return Handle(i, this->m_Table[i].first);
//            }
//        }
//
//        // grow table
//        this->GrowTable();
//
//        this->m_Table[i].first = 1;
//        this->m_Table[i].second = rawObject;
//
//        return Handle(i, this->m_Table[i].first);
    }
    void release( Handle handle ) {}
    bool isExpired( Handle handle ) { return false; }
    Handle operator[]( typename Handle::NumericTyoe index ) const { return Handle(); }
    inline T* operator[]( Handle handle ) { return nullptr; }

private:

    //    std::list< TableEntry > m_list;
    std::vector< Handle::NumericType > m_versions;
    std::deque< Handle::NumericType > m_indices;
};

}

#endif // BEMO_TABLE_HH
