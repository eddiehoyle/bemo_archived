#ifndef BEMO_TABLE_HH
#define BEMO_TABLE_HH

#include <cstddef>
#include <utility>
#include <list>

namespace bemo {

template< typename T, typename H >
class HandleTable {

    using Handle = H;
    using TableEntry = std::pair< typename Handle::NumericType, T* >;

public:
    HandleTable() = default;
    ~HandleTable() = default;

    Handle acquire() { return Handle(); }
    void release( Handle handle ) {}
    bool isExpired( Handle handle ) { return false; }
    Handle operator[]( typename Handle::NumericTyoe index ) const { return Handle(); }
    inline T* operator[]( Handle handle ) { return nullptr; }

private:
    std::list< TableEntry > m_list;
};

}

#endif // BEMO_TABLE_HH
