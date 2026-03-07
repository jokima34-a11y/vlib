#include "vlib/window.hpp"
#include "vlib/event.hpp"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

static GLFWwindow* g_Window = nullptr;

void vInitWindow(int w, int h, const char* title) {
    if (!glfwInit()) {
        std::cout << "Failed to init GLFW" << std::endl;
        return;
    }

    g_Window = glfwCreateWindow(w, h, title, nullptr, nullptr);
    glfwMakeContextCurrent(g_Window);

    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    if (!status) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    
    vSetCallbacks();
}
int vSetCallbacks() {
    //Create events
    vCreateEvent("WindowClose");

    //Assign events
    glfwSetWindowCloseCallback(g_Window, [](GLFWwindow* window) {
        vEvent e;
        e.type = "WindowClose";
        vEventPost(e);
    });

    return 0;
}
void vCloseWindow() {
    glfwDestroyWindow(g_Window);
    glfwTerminate();
}
bool vWindowShouldClose() {
    return glfwWindowShouldClose(g_Window);
}
void vClearScreen(vColorRGBA color=vWHITE) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
}
void vPollBuffers() {
    glfwPollEvents();
    glfwSwapBuffers(g_Window);
}
