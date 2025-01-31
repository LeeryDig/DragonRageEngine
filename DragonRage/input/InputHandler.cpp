#include <iostream>
#include "InputHandler.h"

void ProcessInputEditor(GLFWwindow* window, SysState& sysState) {
    if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS) {
        sysState = SysState::EDITOR;
    }

    if (glfwGetKey(window, GLFW_KEY_F2) == GLFW_PRESS) {
        sysState = SysState::MENU;
    }

    if (glfwGetKey(window, GLFW_KEY_F3) == GLFW_PRESS) {
        sysState = SysState::PLAYING;
    }
}

void ProcessInputGame(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        std::cout << "W";
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        std::cout << "S";
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        std::cout << "A";
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        std::cout << "D";
    }
}
