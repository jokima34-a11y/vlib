#include "vlib/vlib.hpp"
#include <iostream>
int main() {
    vInitWindow(1200, 600, "Bob");
    vEventRequest("WindowClose", [](vEvent&) {
        std::cout << "callbacks working" << std::endl;
    });
    while (!vWindowShouldClose()) {
        vClearScreen(vPURPLE);

        vPollBuffers();
    }
    vCloseWindow();
}
