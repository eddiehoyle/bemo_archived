#ifndef BEMO_VARIANT_HH
#define BEMO_VARIANT_HH

#include <string>

namespace bemo {

enum class VariantType {
    Null,
    Long,
    Float,
    String,
};

class Variant {

public:

    static Variant invalid();

public:
    Variant();
    explicit Variant( long value );
    explicit Variant( float value );
    explicit Variant( const std::string& value );
    ~Variant();

    Variant( const Variant& var );
    Variant& operator=( const Variant& var );

    void clear();
    void reset( const Variant& var );

    VariantType type() const;

    long toLong( bool* result ) const;
    float toFloat( bool* result ) const;
    std::string toString( bool* result ) const;

private:
    void* m_data;
    VariantType m_type;
};

}

#endif // BEMO_VARIANT_HH
