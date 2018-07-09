include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

enable_testing()

set(TEST_MAIN_SOURCE testMain.cc )
set(TEST_ALL_SOURCES
        container/testGraph.cc)
add_executable(test_bemo
        ${TEST_MAIN_SOURCE}
        ${TEST_ALL_SOURCES})
target_link_libraries(test_bemo
        gtest_main
        gtest
        corebemo)