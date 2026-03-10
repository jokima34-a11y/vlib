#include "vlib/vcph.h"
#include "vlib/events/eventService.hpp"
#include "vlib/input/inputService.hpp"

static inline bool          g_Keys[350] = { false };
static inline bool          g_PrevKeys[350] = { false };
static inline bool          g_Mouse[8] = { false };
static inline bool          g_PrevMouse[8] = { false };

void vInit_Input() {
    vGetEvent(EventType::Keyboard, [](vEvent& e) {
        auto& ke = static_cast<KeyboardEvent&>(e);
        if (ke.key >= 0 && ke.key < 350) {
            g_Keys[ke.key] = (ke.action != 0);
        }
    });

    vGetEvent(EventType::Mouse, [](vEvent& e) {
        auto& me = static_cast<MouseButtonEvent&>(e);
        if (me.button >= 0 && me.button < 8) {
            g_Mouse[me.button] = (me.action != 0);
        }
    });
}
void vUpdate_Input() {
    for (int i = 0; i < 350; ++i) g_PrevKeys[i] = g_Keys[i];
    for (int i = 0; i < 8; ++i) g_PrevMouse[i] = g_Mouse[i];
}
bool vIsDown(Input::Key key) {
    return g_Keys[static_cast<int>(key)];
}
bool vIsDown(Input::Mouse button) {
    return g_Mouse[static_cast<int>(button)];
}
bool vWasPressed(Input::Key key) {
    int k = static_cast<int>(key);
    return g_Keys[k] && !g_PrevKeys[k];
}
bool vWasPressed(Input::Mouse button) {
    int b = static_cast<int>(button);
    return g_Mouse[b] && !g_PrevMouse[b];
}
