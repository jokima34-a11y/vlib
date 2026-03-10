#include "vlib/vcph.h"
#include "vlib/vlib.hpp"

int main() {
    std::cout << "VLIB: sandbox/main.cpp" << std::endl;
    vSetInitCallback([]() {
        std::cout << "VLIB: sandbox/main.cpp INTALIZED" << std::endl;
    });
    vSetUpdateCallback([](float dt) {
        if (vIsDown(Input::Key::W)) {
            std::cout << "VLIB: sandbox/main.cpp Currently holding the w key" << std::endl;
        }
        if (vIsDown(Input::Mouse::Left)) {
            std::cout << "VLIB: sandbox/main.cpp Currently holding the left mouse button" << std::endl;
        }
        if (vWasPressed(Input::Key::W)) {
            std::cout << "VLIB: sandbox/main.cpp Pressed the w key" << std::endl;
        }
        if (vWasPressed(Input::Mouse::Left)) {
            std::cout << "VLIB: sandbox/main.cpp Presed the left mouse button" << std::endl;
        }
        if (vWasPressed(Input::Mouse::Right)) {
            std::cout << "VLIB: sandbox/main.cpp Presed the right mouse button" << std::endl;
        }
    });
    vSetShutdownCallback([]() {
        std::cout << "VLIB: sandbox/main.cpp SHUTING DOWN" << std::endl;
    });
    WindowParms parms;
    parms.Title = "OpenGL";
    parms.x = 800;
    parms.y = 600;
    parms.color = vBlack;
    vCreateWindow(parms);
    return 0;
}