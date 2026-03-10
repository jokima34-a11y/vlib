#pragma once
#include "vlib/vcph.h"
#include "vlib/core/defines.hpp"
#include "vlib/events/eventConfig.hpp"

struct V_API vColor {
    union {
        struct { float r, g, b, a; };
        float data[4];
    };

    constexpr vColor(float _r, float _g, float _b, float _a = 1.0f) 
        : r(_r), g(_g), b(_b), a(_a) {}
};

struct V_API vVec2 {
    float x, y;
    operator glm::vec2() const { return glm::vec2(x, y); }
};

struct V_API vVec3 {
    float x, y, z;
    operator glm::vec3() const { return glm::vec3(x, y, z); }
};

using vUpdateCallback = void (*)(float delta);
using vEventCallback = void (*)(vEvent &e);
using vCallback = void (*)();

//Vec2
inline constexpr vVec2 vVec2Zero = { 0, 0};
inline constexpr vVec3 vVec3Zero = { 0, 0, 0};

// RGBA: Red, Green, Blue, Alpha (Transparency)
inline constexpr vColor vRed   { 1.0f, 0.0f, 0.0f, 1.0f };
inline constexpr vColor vWhite { 1.0f, 1.0f, 1.0f, 1.0f };
inline constexpr vColor vGreen { 0.0f, 1.0f, 0.0f, 1.0f };
inline constexpr vColor vBlue  { 0.0f, 0.0f, 1.0f, 1.0f };
inline constexpr vColor vBlack { 0.0f, 0.0f, 0.0f, 1.0f };
