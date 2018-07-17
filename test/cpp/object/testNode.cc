#include <gtest/gtest.h>

#include "../Common.hh"

#include <BCore/object/Node.hh>

using namespace bemo;

TEST_F( BemoAPI, node_ctor ) {

    Node nodeA( NodeID::invalid() );
    

//
//    using HandleShort = Handle< short,
//            sizeof( short ) * CHAR_BIT / 2 + ( sizeof( short ) * CHAR_BIT / 4 ),
//            sizeof( short ) * CHAR_BIT / 4 >;
//    using HandleInt = Handle< int,
//            sizeof( int ) * CHAR_BIT / 2 + ( sizeof( int ) * CHAR_BIT / 4 ),
//            sizeof( int ) * CHAR_BIT / 4 >;
//    using HandleLong = Handle< long,
//            sizeof( long ) * CHAR_BIT / 2 + ( sizeof( long ) * CHAR_BIT / 4 ),
//            sizeof( long ) * CHAR_BIT / 4 >;
//    using HandleUnsignedShort = Handle< unsigned short,
//            sizeof( unsigned short ) * CHAR_BIT / 2 + ( sizeof( unsigned short ) * CHAR_BIT / 4 ),
//            sizeof( unsigned short ) * CHAR_BIT / 4 >;
//    using HandleUnsignedInt = Handle< unsigned int,
//            sizeof( unsigned int ) * CHAR_BIT / 2 + ( sizeof( unsigned int ) * CHAR_BIT / 4 ),
//            sizeof( unsigned int ) * CHAR_BIT / 4 >;
//    using HandleUnsignedLong = Handle< unsigned long,
//            sizeof( unsigned long ) * CHAR_BIT / 2 + ( sizeof( unsigned long ) * CHAR_BIT / 4 ),
//            sizeof( unsigned long ) * CHAR_BIT / 4 >;
//
//    HandleShort handleShort;
//    HandleInt handleInt;
//    HandleLong handleLong;
//    HandleUnsignedShort handleUnsignedShort;
//    HandleUnsignedInt handleUnsignedInt;
//    HandleUnsignedLong handleUnsignedLong;
//
//    // Test ValueType equality
//    EXPECT_EQ( short( handleShort ), short( 0 ) );
//    EXPECT_EQ( int( handleInt ), int( 0 ) );
//    EXPECT_EQ( long( handleLong ), long( 0 ) );
//
//    // Cast due to test expansion
//    EXPECT_EQ( static_cast< unsigned short >( handleUnsignedShort ), static_cast< unsigned short >( 0 ) );
//    EXPECT_EQ( static_cast< unsigned int >( handleUnsignedInt ), static_cast< unsigned int >( 0 ) );
//    EXPECT_EQ( static_cast< unsigned long >( handleUnsignedLong ), static_cast< unsigned long >( 0 ) );
}
