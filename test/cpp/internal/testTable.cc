#include <gtest/gtest.h>

#include "../Common.hh"

#include <BCore/internal/Handle.hh>
#include <BCore/internal/Table.hh>
#include <BCore/Platform.hh>
#include <BCore/object/Graph.hh>

using namespace bemo;

TEST_F( BemoAPI, table_templates ) {
    using Handle32 = Handle< u32, 20, 12 >;
    using Table = HandleTable< Graph, Handle32 >;
    Table table;
}

TEST_F( BemoAPI, table_acquire ) {

    using Handle32 = Handle< u32, 20, 12 >;
    using Table = HandleTable< Graph, Handle32 >;

    Table table;
    Handle32 handle = table.acquire( nullptr );
    EXPECT_EQ( handle.index(), Handle32::MIN_INDEX );
    EXPECT_EQ( handle.version(), Handle32::MIN_VERSION );
}
