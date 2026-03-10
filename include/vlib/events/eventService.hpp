#pragma once
#include "vlib/events/eventConfig.hpp"
#include "vlib/core/constants.hpp"

V_API void vGetEvent(EventType type, vEventCallback callback);
V_API void vPostEvent(vEvent& e);