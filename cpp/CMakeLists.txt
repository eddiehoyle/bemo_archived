set(TARGET_LIBBEMO pybemo)
set(BMO_LOGGING_ENABLED true)
set(BMO_ASSERT_ENABLED true)

include_directories(.)

file(GLOB_RECURSE LIBBEMO_SOURCES BCore/*.cc)
file(GLOB_RECURSE LIBBEMO_HEADERS BCore/*.hh)

pybind11_add_module(${TARGET_LIBBEMO} ${LIBBEMO_SOURCES} ${LIBBEMO_HEADERS})
target_compile_definitions(${TARGET_LIBBEMO}
        PUBLIC
        BMO_LOGGING_ENABLED=${BMO_LOGGING_ENABLED}
        BMO_ASSERT_ENABLED=${BMO_ASSERT_ENABLED}
        )

add_custom_command(TARGET ${TARGET_LIBBEMO} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_LIBBEMO}> ${PYTHON_DIST_DIR})

## Qt5
#set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.7/clang_64/lib/cmake ${CMAKE_PREFIX_PATH} )
#set(CMAKE_AUTOMOC ON)
#
#find_package(Qt5Widgets REQUIRED)
#
#add_executable(${TARGET_UI} ${UIBEMO_SOURCES})
#target_link_libraries(${TARGET_UI} PRIVATE
#        ${TARGET_LIBBEMO} pybind11::embed Qt5::Widgets)
#
#add_dependencies(${TARGET_UI} ${TARGET_PYLIB_API} ${TARGET_LIBBEMO})