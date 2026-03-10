#pragma once
#include "vlib/window/winConfig.hpp"
#include "vlib/core/defines.hpp"
#include "vlib/core/constants.hpp"

V_API float vGetDeltaTime();
V_API const char* vGetTitle();
V_API float vGetScreenWidth();
V_API float vGetScreenHeight();
V_API vVec2 vGetMousePosition();

V_API struct WindowParms {
    const char* Title;
    vColor color = vBlack;
    int x;
    int y;
};

V_API void vSetClearColor(const vColor &color);
//Called right after window creation
V_API void vSetInitCallback(vCallback callback);
//Update logic
V_API void vSetUpdateCallback(vUpdateCallback callback);
//Called during closure
V_API void vSetShutdownCallback(vCallback callback);
//Window should be created, after setting the callbacks 
V_API void vCreateWindow(const WindowParms &parms);