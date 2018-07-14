#include <gtest/gtest.h>

#include "../Common.hh"

#include <BCore/internal/Handle.hh>
#include <BCore/Platform.hh>

using namespace bemo;

TEST_F( BemoAPI, templates ) {

    using HandleShort = Handle< short,
            sizeof( short ) * CHAR_BIT / 2 + ( sizeof( short ) * CHAR_BIT / 4 ),
            sizeof( short ) * CHAR_BIT / 4 >;
    using HandleInt = Handle< int,
            sizeof( int ) * CHAR_BIT / 2 + ( sizeof( int ) * CHAR_BIT / 4 ),
            sizeof( int ) * CHAR_BIT / 4 >;
    using HandleLong = Handle< long,
            sizeof( long ) * CHAR_BIT / 2 + ( sizeof( long ) * CHAR_BIT / 4 ),
            sizeof( long ) * CHAR_BIT / 4 >;
    using HandleUnsignedShort = Handle< unsigned short,
            sizeof( unsigned short ) * CHAR_BIT / 2 + ( sizeof( unsigned short ) * CHAR_BIT / 4 ),
            sizeof( unsigned short ) * CHAR_BIT / 4 >;
    using HandleUnsignedInt = Handle< unsigned int,
            sizeof( unsigned int ) * CHAR_BIT / 2 + ( sizeof( unsigned int ) * CHAR_BIT / 4 ),
            sizeof( unsigned int ) * CHAR_BIT / 4 >;
    using HandleUnsignedLong = Handle< unsigned long,
            sizeof( unsigned long ) * CHAR_BIT / 2 + ( sizeof( unsigned long ) * CHAR_BIT / 4 ),
            sizeof( unsigned long ) * CHAR_BIT / 4 >;

    HandleShort handleShort;
    HandleInt handleInt;
    HandleLong handleLong;
    HandleUnsignedShort handleUnsignedShort;
    HandleUnsignedInt handleUnsignedInt;
    HandleUnsignedLong handleUnsignedLong;

    // Test ValueType equality
    EXPECT_EQ( short( handleShort ), short( 0 ) );
    EXPECT_EQ( int( handleInt ), int( 0 ) );
    EXPECT_EQ( long( handleLong ), long( 0 ) );

    // Cast due to test expansion
    EXPECT_EQ( static_cast< unsigned short >( handleUnsignedShort ), static_cast< unsigned short >( 0 ) );
    EXPECT_EQ( static_cast< unsigned int >( handleUnsignedInt ), static_cast< unsigned int >( 0 ) );
    EXPECT_EQ( static_cast< unsigned long >( handleUnsignedLong ), static_cast< unsigned long >( 0 ) );
}

TEST_F( BemoAPI, default_ctor ) {
    using Handle32 = Handle< u32, 20, 12 >;
    Handle32 handle;
    EXPECT_EQ( u32( handle ), 0 );
}

TEST_F( BemoAPI, explicit_ctor ) {
    using Handle32 = Handle< u32, 20, 12 >;
    Handle32 handle( 3 );
    EXPECT_EQ( u32( handle ), 3 );
}

TEST_F( BemoAPI, copy ) {
    using Handle32 = Handle< u32, 20, 12 >;
    Handle32 handleA( 3 );
    Handle32 handleB = handleA;
    EXPECT_EQ( handleA, handleB );
    EXPECT_EQ( u32( handleA ), u32( handleB ) );
}

TEST_F( BemoAPI, equal ) {
    using Handle32 = Handle< u32, 20, 12 >;
    Handle32 handleA( 3 );
    Handle32 handleB( 3 );
    EXPECT_EQ( handleA, handleB );
    EXPECT_EQ( u32( handleA ), u32( handleB ) );
}

TEST_F( BemoAPI, not_equal ) {
    using Handle32 = Handle< u32, 20, 12 >;
    Handle32 handleA( 2 );
    Handle32 handleB( 3 );
    EXPECT_NE( handleA, handleB );
    EXPECT_NE( u32( handleA ), u32( handleB ) );
}

TEST_F( BemoAPI, less_than ) {
    using Handle32 = Handle< u32, 20, 12 >;
    Handle32 handleA( 2 );
    Handle32 handleB( 5 );
    Handle32 handleC( 8 );
    EXPECT_TRUE( handleA < handleB );
    EXPECT_TRUE( u32( handleA ) < u32( handleB ) );
    EXPECT_FALSE( u32( handleC ) < u32( handleB ) );
}

TEST_F( BemoAPI, greater_than ) {
    using Handle32 = Handle< u32, 20, 12 >;
    Handle32 handleA( 2 );
    Handle32 handleB( 5 );
    Handle32 handleC( 8 );
    EXPECT_TRUE( handleB > handleA );
    EXPECT_TRUE( u32( handleB ) > u32( handleA ) );
    EXPECT_FALSE( handleB > handleC );
    EXPECT_FALSE( u32( handleB ) > u32( handleC ) );
}
