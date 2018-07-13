#ifndef BEMO_COMMON_HH
#define BEMO_COMMON_HH

#include <BCore/API.hh>

class WrapBemo : public ::testing::Test {

protected:
    virtual void SetUp() { bemo::initialize(); }
    virtual void TearDown() { bemo::terminate(); }
};

#endif // BEMO_COMMON_HH
