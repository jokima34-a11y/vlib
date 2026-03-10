#include "vlib/vcph.h"
#include "vlib/events/eventService.hpp"

static std::unordered_map<EventType, std::vector<vEventCallback>> callbacks;
static std::vector<EventType> events;

void vGetEvent(EventType type, vEventCallback callback) {
    callbacks[type].push_back(callback);
}
void vPostEvent(vEvent& e) {
    auto it = callbacks.find(e.GetEventType());
    if (it != callbacks.end()) {
        for (auto& cb : it->second) {
            cb(e);
        }
    }
}