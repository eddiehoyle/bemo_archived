#ifndef BEMO_ASSERT_HH
#define BEMO_ASSERT_HH

#include "Log.hh"

#if BMO_ASSERT_ENABLED
#define STR(exp) #exp
#define BMO_ASSERT(exp)                                         \
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
