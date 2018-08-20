#ifndef BEMO_DATABLOCK_HH
#define BEMO_DATABLOCK_HH

namespace bemo {

enum class DataType {
    Int,
    String,
    Float,
};

class DataBlock {
public:
    explicit DataBlock( int value )
        : m_data( new int( value ) ),
          m_type( DataType::Int ) {}

    ~DataBlock() {
        switch( m_type ) {
            case DataType::Int:
                delete static_cast< int* >( m_data );
                break;
            default:
                break;
        }
    }
private:
    void* m_data;
    DataType m_type;
};
}

#endif // BEMO_DATABLOCK_HH
