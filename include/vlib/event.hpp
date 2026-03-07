#pragma once
#include "vlib/types.hpp"

void vEventRequest(const char* requested, const vEventCallback callback);
void vCreateEvent(const char* type);
void vEventPost(vEvent &event);
bool vCheckEvent(const char* event);
int vGetEventCount();