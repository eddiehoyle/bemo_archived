#ifndef BEMO_COMMON_HH
#define BEMO_COMMON_HH

#include <gtest/gtest.h>

#include <BCore/API.hh>

class BemoAPI : public ::testing::Test {
protected:
    void SetUp() override { bemo::initialize(); }
    void TearDown() override { bemo::terminate(); }
};

#endif // BEMO_COMMON_HH
