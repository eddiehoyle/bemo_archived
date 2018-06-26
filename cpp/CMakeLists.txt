set(TARGET_PYLIB pybemo)
set(TARGET_LIB node)

include_directories(include)

add_library(${TARGET_LIB} SHARED
        src/Node.cc include/Node.hh
        src/Graph.cc include/Graph.hh
        )

pybind11_add_module(${TARGET_PYLIB} src/pybemo.cc)
target_link_libraries(${TARGET_PYLIB} PRIVATE ${TARGET_LIB})

add_custom_command(TARGET ${TARGET_PYLIB} POST_BUILD
        COMMAND
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_PYLIB}>  ${PYTHON_DIST_DIR})

add_custom_command(TARGET ${TARGET_LIB}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_LIB}>  ${PYTHON_DIST_DIR})

