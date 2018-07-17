#ifndef BEMO_ABSTRACTMANAGER_HH
#define BEMO_ABSTRACTMANAGER_HH

#include <BCore/internal/Table.hh>

namespace bemo {

template< typename T, typename H >
class AbstractManager {

public:
    virtual T create() = 0;
    virtual T destroy() = 0;

protected:

    using ObjectType = T;
    using HandleType = H;

    HandleTable< T, H > m_table;
};

}

#endif // BEMO_ABSTRACTMANAGER_HH
