#include "vlib/vcph.h"
#include "vlib/window/windowService.hpp"
#include "vlib/events/eventService.hpp"
#include "vlib/input/inputConfig.hpp"

static WindowParms     g_parms;
static GLFWwindow*     g_window;
static vCallback       g_InitCb     = nullptr;
static vUpdateCallback g_UpdateCb   = nullptr;
static vCallback       g_ShutdownCb = nullptr;
static float           g_LastFrameTime = 0.0f;
static vVec2           g_MousePositions;

//To Implement:
// Event handling
// Input handling

void vSetInitCallback(vCallback callback) {
    g_InitCb = callback;
}
void vSetUpdateCallback(vUpdateCallback callback) {
    g_UpdateCb = callback;
}
void vSetShutdownCallback(vCallback callback) {
    g_ShutdownCb = callback;
}
float vGetDeltaTime() {
    float currentFrame = static_cast<float>(glfwGetTime());
    float dt = currentFrame - g_LastFrameTime;
    g_LastFrameTime = currentFrame;
    return dt;
}
float vGetScreenWidth() {
    return g_parms.x;
}
float vGetScreenHeight() {
    return g_parms.y;
}
const char* vGetTitle() {
    return g_parms.Title;
}
vVec2 vGetMousePosition() {
    return g_MousePositions;
}
void vSetClearColor(const vColor &n_color) {
    g_parms.color = n_color;
}
void vInternal_vSetGLFWCallbacks() {
    glfwSetFramebufferSizeCallback(g_window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height); 
        g_parms.x = width;
        g_parms.y = height;
    });

    glfwSetCursorPosCallback(g_window, [](GLFWwindow* window, double xpos, double ypos) {
        g_MousePositions.x = xpos;
        g_MousePositions.y = ypos;
    });

    glfwSetWindowCloseCallback(g_window, [](GLFWwindow* window) {
        vWindowCloseEvent e;
        vPostEvent(e);
    });

    glfwSetKeyCallback(g_window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        KeyboardEvent e;
        e.key = key;
        e.action = action;
        vPostEvent(e);  
    });

    glfwSetMouseButtonCallback(g_window, [](GLFWwindow* window, int button, int action, int mods) {
        MouseButtonEvent e;
        e.button = button;
        e.action = action;
        vPostEvent(e);
    });
}
void vInternal_vCreateGLFWWindow() {
    if (!glfwInit()) {
        std::cout << "VLIB ERROR: Failed to init GLFW" << std::endl;
        return;
    }
    g_window = glfwCreateWindow(vGetScreenWidth(), vGetScreenHeight(), vGetTitle(), nullptr, nullptr);
    if (!g_window) {
        std::cerr << "VLIB ERROR: Failed to create Window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(g_window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
} 
void vInternal_vStartFrame() {
    vUpdate_Input();
    glfwPollEvents();
    glClearColor(
        g_parms.color.r, 
        g_parms.color.g, 
        g_parms.color.b, 
        g_parms.color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}
void vInternal_vEndFrame() {
    glfwSwapBuffers(g_window);
}
void vInternal_Cleanup() {
    glfwDestroyWindow(g_window);
    glfwTerminate();
}
void vCreateWindow(const WindowParms &parms) {
    g_parms = parms;
    vInternal_vCreateGLFWWindow();
    vInternal_vSetGLFWCallbacks();
    if (g_InitCb) g_InitCb();
    vInit_Input();
    g_LastFrameTime = static_cast<float>(glfwGetTime());
    while (!glfwWindowShouldClose(g_window)) {
        vInternal_vStartFrame();
        if (g_UpdateCb) g_UpdateCb(vGetDeltaTime());
        vInternal_vEndFrame();
    }
    if (g_ShutdownCb) g_ShutdownCb();
    vInternal_Cleanup();
}
