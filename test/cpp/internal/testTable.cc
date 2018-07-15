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
    Handle32 handleA = table.acquire( nullptr );
    EXPECT_EQ( handleA.index(), Handle32::MIN_INDEX );
    EXPECT_EQ( handleA.version(), Handle32::MIN_VERSION );

    Handle32 handleB = table.acquire( nullptr );
    EXPECT_EQ( handleB.index(), Handle32::MIN_INDEX + 1 );
    EXPECT_EQ( handleB.version(), Handle32::MIN_VERSION );
}

TEST_F( BemoAPI, table_loop_acquire ) {

    using Handle32 = Handle< u32, 4, 2 >;
    using Table = HandleTable< Graph, Handle32 >;

    BMO_ERROR << Handle32::MAX_INDICES;

    // Use up all slots
    Table table;
    Handle32 handleA = table.acquire( nullptr );
    for ( std::size_t i = 0; i < Handle32::MAX_INDICES-1; ++i ) {
        table.acquire( nullptr );
    }

    // Should re-use first slot
    Handle32 handleB = table.acquire( nullptr );

    EXPECT_EQ( handleA, handleB );
}
