set(TARGET_PYLIB pybemo)
set(TARGET_LIB node)
set(TARGET_EXE app)

include_directories(include)

add_library(${TARGET_LIB} SHARED
        src/Node.cc
        src/Graph.cc)

pybind11_add_module(${TARGET_PYLIB} src/pybemo.cc)
target_link_libraries(${TARGET_PYLIB} PRIVATE ${TARGET_LIB})

add_custom_command(TARGET ${TARGET_PYLIB} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_PYLIB}> ${PYTHON_DIST_DIR})

add_custom_command(TARGET ${TARGET_LIB}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_LIB}> ${PYTHON_DIST_DIR})


# Qt5
set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.7/clang_64/lib/cmake ${CMAKE_PREFIX_PATH} )
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

add_executable(${TARGET_EXE}
        src/ui/Main.cc
        src/ui/Window.cc
        src/ui/Outliner.cc
        src/ui/ScriptEditor.cc)
target_link_libraries(${TARGET_EXE} PRIVATE
        ${TARGET_LIB} pybind11::embed Qt5::Widgets)

add_dependencies(${TARGET_EXE} ${TARGET_PYLIB} ${TARGET_LIB})