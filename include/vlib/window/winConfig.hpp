#pragma once
#include "vlib/core/defines.hpp"
#include "vlib/core/constants.hpp"

void vInternal_SetGLFWCallbacks();
void vInternal_vCreateGLFWWindow(); 
void vInternal_vEndFrame();
void vInternal_vStartFrame();
void vInternal_Cleanup();
