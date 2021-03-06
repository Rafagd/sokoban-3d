cmake_minimum_required(VERSION 2.6)

project("Sokoban 3d")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

find_package(PkgConfig REQUIRED)
pkg_search_module(ASSIMP REQUIRED assimp)
pkg_search_module(BSD    REQUIRED libbsd)
pkg_search_module(GLU    REQUIRED glu)
pkg_search_module(GLEE   REQUIRED glee)
pkg_search_module(GLFW   REQUIRED glfw3)

include_directories("include")
include_directories(${ASSIMP_INCLUDE_DIRS})
include_directories(${BSD_INCLUDE_DIRS})
include_directories(${GLU_INCLUDE_DIRS})
include_directories(${GLEE_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})

file(GLOB_RECURSE SOKOBAN_SRC "src/*.c" "src/*.cpp")

add_executable(sokoban-3d ${SOKOBAN_SRC})

target_link_libraries(sokoban-3d
    m
    ${ASSIMP_LIBRARIES}
    ${BSD_LIBRARIES}
    ${GLU_LIBRARIES}
    ${GLEE_LIBRARIES}
    ${GLFW_LIBRARIES}
)

