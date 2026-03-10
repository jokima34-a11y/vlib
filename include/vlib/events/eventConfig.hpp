#pragma once
#include "vlib/core/defines.hpp"

#define V_EVENT_TYPE(type_enum) \
    static EventType GetStaticType() { return EventType::type_enum; } \
    virtual EventType GetEventType() const override { return GetStaticType(); }

enum class EventType {
    WindowClose,
    Mouse,
    Keyboard,
};

struct vEvent {
    bool handled=false;
    virtual EventType GetEventType() const = 0; 
};

struct vWindowCloseEvent : public vEvent {
    V_EVENT_TYPE(WindowClose)
};

struct MouseButtonEvent : public vEvent {
    V_EVENT_TYPE(Mouse)
    int button;
    //1 is press
    //0 is release
    int action;
};

struct KeyboardEvent : public vEvent {
    V_EVENT_TYPE(Keyboard)
    int key;
    int action;
};