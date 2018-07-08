#ifndef BEMO_ASSERT_HH
#define BEMO_ASSERT_HH

#include "Log.hh"

#if BEMO_ASSERT_ENABLED
#define STR(exp) #exp
#define BMOASSERT(exp)                                         \
do {                                                            \
    if ( !( exp ) ) {                                           \
        BMO_ERROR << "Assertion failed: (" << STR(exp) << ") "  \
                  << "[" << __FILE__ << ":" << __LINE__ << "]"; \
        abort();                                                \
    }                                                           \
} while(0);
#else
#define BMO_ASSERT(ignore)
#endif

#endif // BEMO_ASSERT_HH
