cmake_minimum_required(VERSION 3.16)
project(VLIB_Engine VERSION 0.1.0 LANGUAGES CXX C)

#Set cmake standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory("external/glfw")

#vlib .hpp's/.h
set(ENGINE_HEADERS
    "include/vlib/core/defines.hpp"
    "include/vlib/core/constants.hpp"
    "include/vlib/window/windowService.hpp"
    "include/vlib/window/winConfig.hpp"
    "include/vlib/events/eventConfig.hpp"
    "include/vlib/events/eventService.hpp"
    "include/vlib/input/inputConfig.hpp"
    "include/vlib/input/inputService.hpp"
    "include/vlib/vlib.hpp"
    "include/vlib/vcph.h"
)

#vlib .cpp's/.c
set(ENGINE_SOURCES
    "src/glad.c"
    "src/vcph.cpp"
    "src/input.cpp"
    "src/event.cpp"
    "src/window.cpp"
)

#Create the acctural library as a .dll (Shared)
add_library(vlib SHARED ${ENGINE_SOURCES} ${ENGINE_HEADERS})
set_source_files_properties(src/glad.c PROPERTIES SKIP_PRECOMPILE_HEADERS ON)

target_link_libraries(vlib 
    PRIVATE 
        glfw 
        opengl32
)

target_include_directories(vlib 
    #include is public so src can find the headers during compile time
    PUBLIC  
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
#Precompiled includes
target_precompile_headers(vlib PRIVATE include/vlib/vcph.h)

#Get the platform
target_compile_definitions(vlib PUBLIC $<$<PLATFORM_ID:Windows>:V_PLATFORM_WINDOWS>)
#V_BUILD_DLL acts as a flag, if it's true when building it'll export (put the functions in a file)
#When it's not, or in sandbox mode it'll just tell were the functions are located
target_compile_definitions(vlib PRIVATE V_BUILD_DLL)

if(MSVC)
    target_compile_options(vlib PRIVATE /W4)
else()
    target_compile_options(vlib PRIVATE -Wall -Wextra)
endif()

set(SANDBOX_SOURCES "sandbox/src/main.cpp")
add_executable(Sandbox ${SANDBOX_SOURCES})
target_link_libraries(Sandbox PRIVATE vlib)

add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:vlib>
    $<TARGET_FILE_DIR:Sandbox>
)