#ifndef BEMO_DATABLOCK_HH
#define BEMO_DATABLOCK_HH

#include <BCore/Variant.hh>
#include <BCore/internal/Object.hh>

namespace bemo {

class DataBlockManager;

class DataBlock {

    friend class DataBlockManager;
public:
    explicit DataBlock( const Variant& var )
        : m_variant( var ),
          m_id() {}
private:
    Variant m_variant;
    ObjectID m_id;
};
}

#endif // BEMO_DATABLOCK_HH
