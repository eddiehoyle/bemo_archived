#include <gtest/gtest.h>
#include <utility>

#include <BCore/API.hh>
#include <BCore/container/Graph.hh>
#include <BCore/managers/ContainerManager.hh>

using namespace bemo;

class TestGraph : public ::testing::Test {
protected:
    virtual void SetUp() { initialize(); }
    virtual void TearDown() { terminate(); }
};

TEST_F( TestGraph, ctor ) {
    EXPECT_TRUE( BMO_ContainerManager != nullptr );
}

TEST_F( TestGraph, create ) {
    Graph* graph = BMO_ContainerManager->create< Graph >();
    EXPECT_TRUE( true );
}

//class Grenade {};
//class Backpack {};
//class Player {};
//
//TEST( TestEntity, initialise_id ) {
//    concussion::Entity< Grenade > grenade;
//    EXPECT_EQ( grenade.getID(), 0 );
//}
//
//TEST( TestEntity, initialise_typeid ) {
//    concussion::Entity< Grenade > grenade;
//    EXPECT_EQ( grenade.getTypeID(), 0 );
//}
//
//TEST( TestEntity, same_typeid ) {
//    concussion::Entity< Grenade > grenadeA;
//    concussion::Entity< Grenade > grenadeB;
//    EXPECT_EQ( grenadeA.getTypeID(), 0 );
//    EXPECT_EQ( grenadeB.getTypeID(), 0 );
//}
//
//TEST( TestEntity, different_typeid ) {
//
//    concussion::Entity< Grenade > grenade;
//    concussion::Entity< Backpack > backpack;
//    concussion::Entity< Player > player;
//
//    std::set< concussion::EntityTypeID > types;
//
//    // Remember, these are compile time IDs. Any subsequent
//    // tests will re-use IDs from types found in other tests.
//    EXPECT_TRUE( types.insert( grenade.getTypeID() ).second );
//    EXPECT_TRUE( types.insert( backpack.getTypeID() ).second );
//    EXPECT_TRUE( types.insert( player.getTypeID() ).second );
//}
