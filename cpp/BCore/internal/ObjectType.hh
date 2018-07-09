#ifndef BEMO_TYPE_HH
#define BEMO_TYPE_HH

#include <BCore/Platform.hh>

namespace bemo {

namespace internal {

template< typename T >
class ObjectTypeID{

public:
    template< typename U >
    static const TypeID allocate() {
        static const TypeID objectID { s_count++ };
        return objectID;
    }

private:
    static TypeID s_count;

};

template<typename T>
bemo::TypeID ObjectTypeID<T>::s_count = 0u;

} // namespace internal

} // namespace bemo

#endif // BEMO_TYPE_HH
