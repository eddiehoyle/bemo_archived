#include <gtest/gtest.h>

#include <BCore/internal/Handle.hh>
#include <BCore/util/Log.hh>
#include <BCore/Platform.hh>

#include "../Common.hh"

using namespace bemo;


TEST_F( WrapBemo, ctor ) {
    using Handle32 = Handle< u32, 20, 12 >;
    Handle32 handle;
    BMO_ERROR << "index=" << handle.index() << ", version=" << handle.version();
    EXPECT_EQ( u32( handle ), 0 );
}
