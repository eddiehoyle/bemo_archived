#include <gtest/gtest.h>

#include "../Common.hh"

#include <BCore/internal/Handle.hh>
#include <BCore/internal/Table.hh>
#include <BCore/Platform.hh>
#include <BCore/object/Graph.hh>

using namespace bemo;
using TinyHandy = Handle< u32, 4, 4 >;

TEST_F( BemoAPI, table_templates ) {

    using Table = HandleTable< Graph, TinyHandy >;
    Table table;
}

TEST_F( BemoAPI, table_acquire ) {

    using Table = HandleTable< Graph, TinyHandy >;

    Table table;
    TinyHandy handleA = table.acquire( nullptr );
    EXPECT_EQ( handleA.index(), TinyHandy::MIN_INDEX );
    EXPECT_EQ( handleA.version(), TinyHandy::MIN_VERSION );

    TinyHandy handleB = table.acquire( nullptr );
    EXPECT_EQ( handleB.index(), TinyHandy::MIN_INDEX + 1 );
    EXPECT_EQ( handleB.version(), TinyHandy::MIN_VERSION );
}


TEST_F( BemoAPI, table_release ) {

    using Table = HandleTable< Graph, TinyHandy >;

    Table table;
    TinyHandy handleA = table.acquire( nullptr );
    table.release( handleA );
    TinyHandy handleB = table.acquire( nullptr );

    EXPECT_TRUE( table.isExpired( handleA ) );
    EXPECT_FALSE( table.isExpired( handleB ) );
    EXPECT_NE( handleA.index(), handleB.index() );
    EXPECT_EQ( handleA.version(), handleB.version() );
}

TEST_F( BemoAPI, table_acquire_index_loop ) {

    using Table = HandleTable< Graph, TinyHandy >;

    std::size_t scalar = 4;

    // Use up all slots
    Table table;
    TinyHandy handleA = table.acquire( nullptr );
    for ( std::size_t i = 0; i < TinyHandy::MAX_INDICES * scalar -1; ++i ) {
        table.acquire( nullptr );
    }

    // Should re-use first slot
    TinyHandy handleB = table.acquire( nullptr );

    EXPECT_EQ( handleA.index(), handleB.index() );
}

TEST_F( BemoAPI, table_acquire_version_loop ) {

    using Table = HandleTable< Graph, TinyHandy >;

    std::size_t scalar = 4;

    // Use up all slots
    Table table;
    TinyHandy handleA = table.acquire( nullptr );
    table.release( handleA );
    for ( std::size_t i = 0; i < TinyHandy::MAX_INDICES * scalar - 1; ++i ) {
        table.release( table.acquire( nullptr ) );
    }

    // Should re-use first slot
    TinyHandy handleB = table.acquire( nullptr );

    EXPECT_NE( handleA.version(), handleB.version() );
    EXPECT_EQ( handleB.version(), scalar );
}

TEST_F( BemoAPI, table_access ) {

    using Table = HandleTable< Graph, TinyHandy >;

    Graph* objectA = new Graph( ObjectID::invalid() );
    Graph* objectB = nullptr;

    Table table;
    TinyHandy handleA = table.acquire( objectA );
    objectB = table[ handleA ];

    EXPECT_EQ( objectA, objectB );

    // Cleanup
    delete objectA;
    objectA = nullptr;
    objectB = nullptr;
}
