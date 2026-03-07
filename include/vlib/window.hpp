#pragma once
#include "vlib/types.hpp"

void vInitWindow(int w, int h, const char* title);
int vSetCallbacks();
bool vWindowShouldClose();
void vCloseWindow();
//Update-loop
void vClearScreen(vColorRGBA color);
void vPollBuffers();
