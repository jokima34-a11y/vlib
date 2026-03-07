cmake_minimum_required(VERSION 3.20)
project(vlib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)

set(VLIB_SOURCES
    main.cpp
    src/window.cpp
    src/events.cpp
    src/glad.c
)

add_executable(vlib ${VLIB_SOURCES})

target_include_directories(vlib PRIVATE
    include 
    external/glad
    external/glfw/include
    external 
)

target_link_libraries(vlib PRIVATE glfw)

if (WIN32)
    target_link_libraries(vlib PRIVATE opengl32)
elseif(APPLE)
    target_link_libraries(vlib PRIVATE "-framework OpenGL" "-framework Cocoa" "-framework IOKit")
else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(vlib PRIVATE OpenGL::GL)
endif()