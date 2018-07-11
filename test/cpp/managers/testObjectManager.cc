#include <gtest/gtest.h>
#include <utility>

#include <BCore/API.hh>
#include <BCore/util/Log.hh>
#include <BCore/container/Graph.hh>
#include <BCore/managers/ObjectManager.hh>

using namespace bemo;

class TestObjectManager : public ::testing::Test {

    friend class ObjectManager;

protected:
    virtual void SetUp() { initialize(); }
    virtual void TearDown() { terminate(); }
};

TEST_F( TestObjectManager, ctor ) {
    EXPECT_TRUE( BMO_ObjectManager != nullptr );
}

TEST_F( TestObjectManager, create ) {
    ObjectID id = BMO_ObjectManager->create< Graph >();
    EXPECT_TRUE( true );
}

TEST_F( TestObjectManager, destroy ) {
    ObjectID id = BMO_ObjectManager->create< Graph >();
    BMO_ObjectManager->destroy( id );
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
