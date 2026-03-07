#include "vlib/event.hpp"
#include <unordered_map>
#include <string>
#include <vector>
#include <cstring>

static std::unordered_map<std::string, std::vector<vEventCallback>> callbacks;
static std::vector<std::string> events;

bool vCheckEvent(const char* type) {
    for (const auto& e : events) {
        if (strcmp(type, e.c_str()) == 0) return true;
    }
    return false;
}

void vCreateEvent(const char* event) {
    if (vCheckEvent(event)) return;
    events.push_back(event);
}

void vEventRequest(const char* requested, vEventCallback callback) {
    if (!vCheckEvent(requested)) return;
    callbacks[std::string(requested)].push_back(callback);
}

void vEventPost(vEvent& event) {
    auto it = callbacks.find(std::string(event.type));
    if (it != callbacks.end()) {
        for (auto& cb : it->second) {
            cb(event);
        }
    }
}