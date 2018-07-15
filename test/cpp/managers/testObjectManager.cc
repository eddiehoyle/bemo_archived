#include <gtest/gtest.h>
#include <utility>

#include "../Common.hh"

#include <BCore/API.hh>
#include <BCore/util/Log.hh>
#include <BCore/container/Graph.hh>
#include <BCore/managers/ObjectManager.hh>
#include <BCore/internal/Handle.hh>
#include <deque>

using namespace bemo;
//
//class TestObjectManager : public ::testing::Test {
//
//    friend class ObjectManager;
//
//protected:
//    virtual void SetUp() { initialize(); }
//    virtual void TearDown() { terminate(); }
//};
//
//unsigned int ENTITY_INDEX_BITS = 24U;
//unsigned int ENTITY_INDEX_MASK = (1U<<ENTITY_INDEX_BITS);
//
//unsigned int ENTITY_GENERATION_BITS = 8U;
//unsigned int ENTITY_GENERATION_MASK = (1U<<ENTITY_GENERATION_BITS);
//
//struct Entity {
//    unsigned id;
//    unsigned index() const {return id & ENTITY_INDEX_MASK;}
//    unsigned generation() const {return (id >> ENTITY_INDEX_BITS) & ENTITY_GENERATION_MASK;}
//};
//
//std::size_t MINIMUM_FREE_INDICES = 128;
//Entity make_entity( unsigned int id, unsigned char gen ) {
//    BMO_ERROR << "id=" << id << ", gen=" << gen;
//    Entity entity;
//    return entity;
//}
//
//class EntityManager {
//    std::vector<unsigned char> _generation;
//    std::deque<unsigned int> _free_indices;
//
//public:
//    Entity create() {
//        unsigned int id;
//        if (_free_indices.size() > MINIMUM_FREE_INDICES) {
//            id = _free_indices.front();
//            _free_indices.pop_front();
//        } else {
//            _generation.push_back(0);
//            id = _generation.size() - 1;
//            BMO_ASSERT(id < (1 << ENTITY_INDEX_BITS));
//        }
//        return make_entity(id, _generation[id]);
//    }
//
//    bool alive(Entity e) const {
//        return _generation[e.index()] == e.generation();
//    }
//
//    void destroy(Entity e) {
//        const unsigned int id = e.index();
//        ++_generation[id];
//        _free_indices.push_back(id);
//    }
//};
//

TEST_F( BemoAPI, ctor ) {
    EXPECT_TRUE( BMO_ObjectManager != nullptr );
}

TEST_F( BemoAPI, create ) {
    EXPECT_TRUE( true );
}
