#pragma once

#ifdef _WIN32
    #define V_PLATFORM_WINDOWS
#elif defined(__linux__)
    #define V_PLATFORM_LINUX
#else
    #error "V-Lib only supports Windows and Linux!"
#endif

#ifdef V_PLATFORM_WINDOWS
    #ifdef V_BUILD_DLL
        #define V_API __declspec(dllexport)
    #else
        #define V_API __declspec(dllimport)
    #endif
#else
    #define V_API __attribute__((visibility("default")))
#endif