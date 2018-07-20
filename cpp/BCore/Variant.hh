#ifndef BEMO_VARIANT_HH
#define BEMO_VARIANT_HH

namespace bemo {

class Variant {
public:
    static int invalid() { return -1; }
public:
    explicit Variant( int value ) {}
    explicit Variant( const std::string& string ) {}
    std::string toString() { return ""; }
};

}

#endif // BEMO_VARIANT_HH
