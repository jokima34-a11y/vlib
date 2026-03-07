#pragma once

// Structs
struct vColorRGBA {
    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;
    float a = 1.0f;
};

struct vEvent {
    const char* type;
};

//Typedef
using vCallback = void (*)();
using vEventCallback = void (*)(vEvent &e);

//Colors
inline constexpr vColorRGBA vBLACK      = { 0.0f, 0.0f, 0.0f, 1.0f };
inline constexpr vColorRGBA vWHITE      = { 1.0f, 1.0f, 1.0f, 1.0f };
inline constexpr vColorRGBA vBLANK      = { 0.0f, 0.0f, 0.0f, 0.0f };

inline constexpr vColorRGBA vRED        = { 0.901f, 0.160f, 0.215f, 1.0f };
inline constexpr vColorRGBA vGREEN      = { 0.0f,   0.894f, 0.188f, 1.0f };
inline constexpr vColorRGBA vBLUE       = { 0.0f,   0.474f, 0.945f, 1.0f };
inline constexpr vColorRGBA vYELLOW     = { 0.992f, 0.976f, 0.0f,   1.0f };
inline constexpr vColorRGBA vORANGE     = { 1.0f,   0.631f, 0.0f,   1.0f };
inline constexpr vColorRGBA vPURPLE     = { 0.784f, 0.478f, 1.0f,   1.0f };

inline constexpr vColorRGBA vDARKGREY   = { 0.313f, 0.313f, 0.313f, 1.0f };
inline constexpr vColorRGBA vGREY       = { 0.509f, 0.509f, 0.509f, 1.0f };
inline constexpr vColorRGBA vLIGHTGREY  = { 0.745f, 0.745f, 0.745f, 1.0f };

inline constexpr vColorRGBA vSKYBLUE    = { 0.400f, 0.749f, 1.0f,   1.0f };
inline constexpr vColorRGBA vLIME       = { 0.0f,   0.619f, 0.184f, 1.0f };
inline constexpr vColorRGBA vGOLD       = { 1.0f,   0.796f, 0.0f,   1.0f };
inline constexpr vColorRGBA vMAGENTA    = { 1.0f,   0.0f,   1.0f,   1.0f };