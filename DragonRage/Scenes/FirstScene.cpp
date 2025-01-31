#include "FirstScene.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

void FirstScene::load() {
    std::cout << "First Scene Loaded\n";
    glfwSetMouseButtonCallback(glfwGetCurrentContext(), mouseCallback);

    // Load assets, create objects, initialize game state
}

void FirstScene::update(float dt) {
    std::cout << std::to_string(dt) + "\n";
    // Update game objects, physics, input handling
}

void FirstScene::render() {
    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.2f, 0.2f, 0.5f, 1.0f);

    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
    // Draw objects, player, environment
}

void FirstScene::unload() {
    std::cout << "First Scene Unloaded\n";
    // Cleanup memory, remove game objects
}

void FirstScene::initializeInput(GLFWwindow* window) {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void FirstScene::mouseCallback(GLFWwindow* window, int button, int action, int mods) {
    float r = (float)(rand() % 2);
    float g = (float)(rand() % 2);
    float b = (float)(rand() % 2);
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        glClearColor(r, g, b, 1.0f);
    }
}