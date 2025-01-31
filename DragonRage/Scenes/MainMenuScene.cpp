#include "MainMenuScene.h"

Button MainMenuScene::playButton = { 350, 250, 100, 50, "Play" };

void MainMenuScene::load() {
    std::cout << "Main Menu Scene Loaded\n";

    glClearColor(0.2f, 0.5f, 0.2f, 1.0f);
    glfwSetMouseButtonCallback(glfwGetCurrentContext(), mouseCallback);
}

void MainMenuScene::update(float dt) {}

void MainMenuScene::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MainMenuScene::unload() {
    std::cout << "Main Menu Scene Unloaded\n";
}

void MainMenuScene::initializeInput(GLFWwindow* window) {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
}

void MainMenuScene::mouseCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        ypos = 800 - ypos;

        if (xpos >= playButton.x && xpos <= playButton.x + playButton.width &&
            ypos >= playButton.y && ypos <= playButton.y + playButton.height) {
            std::cout << "Play button clicked!\n";
            SceneManager* sm = static_cast<SceneManager*>(glfwGetWindowUserPointer(window));
            if (sm) {
                sm->setScene(std::make_unique<FirstScene>(*sm));
            }
        }
    }
}