#include "MainMenuScene.h"

Button MainMenuScene::playButton = { 350, 250, 100, 50, "Play" };

MainMenuScene::MainMenuScene(SceneManager& manager)
    : sceneManager(manager) {
    shader = new Shader("../shaders/vertex_shader.glsl", "../shaders/fragment_shader.glsl");
}

void MainMenuScene::load() {
    std::cout << "Main Menu Scene Loaded\n";

    glClearColor(0.2f, 0.5f, 0.2f, 1.0f);
    glfwSetMouseButtonCallback(glfwGetCurrentContext(), mouseCallback);
}

void MainMenuScene::update(float dt) {}

void MainMenuScene::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Use the shader program
    shader->use();

    // Set up orthographic projection (800x600 window)
    glm::mat4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
    shader->setMat4("projection", projection);

    // Draw button
    float buttonVertices[] = {
        350.0f, 250.0f,
        450.0f, 250.0f,
        450.0f, 300.0f,
        350.0f, 300.0f
    };

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(buttonVertices), buttonVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_QUADS, 0, 4);

    // Cleanup
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
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