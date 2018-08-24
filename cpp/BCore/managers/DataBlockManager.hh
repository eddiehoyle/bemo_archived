#ifndef BEMO_VARIANTMANAGER_HH
#define BEMO_VARIANTMANAGER_HH

#include "ObjectManager.hh"
#include <BCore/object/DataBlock.hh>
#include <BCore/internal/Object.hh>

namespace bemo {

class DataBlockManager {

public:

    template< typename T >
    ObjectID create( const T& data ) {
        ObjectID id = BMO_ObjectManager->acquire( ObjectType::Data );
        DataBlock* block = new DataBlock( Variant( data ) );
        block->m_id = id;
        m_dataBlocks.push_back( block );
        return id;
    }

    DataBlock* find( const ObjectID& id ) const {
        auto iter = std::find_if( m_dataBlocks.begin(),
                                  m_dataBlocks.end(),
                                  [id]( DataBlock* block ) {
                                      return block->m_id == id;
                                  });
        return iter != m_dataBlocks.end() ? *iter : nullptr;
    }

private:
    std::vector< DataBlock* > m_dataBlocks;
};

}

#endif // BEMO_VARIANTMANAGER_HH
