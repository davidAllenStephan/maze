cmake_minimum_required(VERSION 3.14)
project(MAZE VERSION 1.0.0.0 LANGUAGES CXX)

find_package(SDL2 REQUIRED)

find_package(Doxygen)

if (DOXYGEN_FOUND)
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating HTML documentation with Doxygen"
        VERBATIM
    )
else()
    message(STATUS "Doxygen not found, 'doc' target will not be available")
endif()


set(SOURCES
    src/disjoint_set.cpp
    src/dyn_array.cpp
    src/kruskals.cpp
    src/matrix.cpp
)

add_library(maze OBJECT ${SOURCES})
target_include_directories(maze PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main app/main.cpp)

target_link_libraries(main
    PRIVATE
        maze
        SDL2::SDL2
)

set_target_properties(maze main PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED NO
    CXX_EXTENSIONS NO
)

