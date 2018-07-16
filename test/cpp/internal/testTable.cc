#include <gtest/gtest.h>

#include "../Common.hh"

#include <BCore/internal/Handle.hh>
#include <BCore/internal/Table.hh>
#include <BCore/Platform.hh>
#include <BCore/object/Graph.hh>

using namespace bemo;

TEST_F( BemoAPI, table_templates ) {
    using Handle32 = Handle< u32, 16, 16 >;
    using Table = HandleTable< Graph, Handle32 >;
    Table table;
}

TEST_F( BemoAPI, table_acquire ) {

    using Handle32 = Handle< u32, 16, 16 >;
    using Table = HandleTable< Graph, Handle32 >;

    Table table;
    Handle32 handleA = table.acquire( nullptr );
    EXPECT_EQ( handleA.index(), Handle32::MIN_INDEX );
    EXPECT_EQ( handleA.version(), Handle32::MIN_VERSION );

    Handle32 handleB = table.acquire( nullptr );
    EXPECT_EQ( handleB.index(), Handle32::MIN_INDEX + 1 );
    EXPECT_EQ( handleB.version(), Handle32::MIN_VERSION );
}


TEST_F( BemoAPI, table_release ) {

    using Handle32 = Handle< u32, 16, 16 >;
    using Table = HandleTable< Graph, Handle32 >;

    Table table;
    Handle32 handleA = table.acquire( nullptr );
    table.release( handleA );
    Handle32 handleB = table.acquire( nullptr );

    EXPECT_TRUE( table.isExpired( handleA ) );
    EXPECT_FALSE( table.isExpired( handleB ) );
    EXPECT_NE( handleA.index(), handleB.index() );
    EXPECT_EQ( handleA.version(), handleB.version() );
}

TEST_F( BemoAPI, table_acquire_index_loop ) {

    using Handle32 = Handle< u32, 16, 16 >;
    using Table = HandleTable< Graph, Handle32 >;

    std::size_t scalar = 4;

    // Use up all slots
    Table table;
    Handle32 handleA = table.acquire( nullptr );
    for ( std::size_t i = 0; i < Handle32::MAX_INDICES * scalar -1; ++i ) {
        table.acquire( nullptr );
    }

    // Should re-use first slot
    Handle32 handleB = table.acquire( nullptr );

    EXPECT_EQ( handleA.index(), handleB.index() );
}

TEST_F( BemoAPI, table_acquire_version_loop ) {

    using Handle32 = Handle< u32, 16, 16 >;
    using Table = HandleTable< Graph, Handle32 >;

    std::size_t scalar = 4;

    // Use up all slots
    Table table;
    Handle32 handleA = table.acquire( nullptr );
    table.release( handleA );
    for ( std::size_t i = 0; i < Handle32::MAX_INDICES * scalar - 1; ++i ) {
        table.release( table.acquire( nullptr ) );
    }

    // Should re-use first slot
    Handle32 handleB = table.acquire( nullptr );

    EXPECT_NE( handleA.version(), handleB.version() );
    EXPECT_EQ( handleB.version(), scalar );
}

TEST_F( BemoAPI, table_access ) {

    using Handle32 = Handle< u32, 16, 16 >;
    using Table = HandleTable< int, Handle32 >;

    int* objectA = new int( 3 );
    int* objectB = nullptr;

    Table table;
    Handle32 handleA = table.acquire( objectA );
    objectB = table[ handleA ];

    EXPECT_EQ( objectA, objectB );

    BMO_ERROR << "size=" << sizeof( handleA ) * CHAR_BIT;

    // Cleanup
    delete objectA;
    objectA = nullptr;
    objectB = nullptr;
}
