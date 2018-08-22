#ifndef BEMO_VARIANT_HH
#define BEMO_VARIANT_HH

#include <string>

namespace bemo {

enum class VariantType {
    Null,
    Int,
    Float,
    String,
};

class Variant {
public:
    Variant();
    explicit Variant( int value );
    explicit Variant( float value );
    explicit Variant( const std::string& value );
    ~Variant();

    Variant( const Variant& var );

    VariantType type() const;

    int toInt( bool* result ) const;
    float toFloat( bool* result ) const;
    std::string toString( bool* result ) const;

private:
    void* m_data;
    VariantType m_type;
};

}

#endif // BEMO_VARIANT_HH
