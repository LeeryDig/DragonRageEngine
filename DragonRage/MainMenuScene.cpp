//#include "MainMenuScene.h"
//
//Button MainMenuScene::playBtn = { 500, 400, 100, 30, 0.6f, 0.1f, 0.1f, "Play" };
//
//MainMenuScene::MainMenuScene(SceneManager& manager)
//    : sceneManager(manager), VAO(0), VBO(0), EBO(0), shader(nullptr) {}
//
//void MainMenuScene::load() {
//    std::cout << "Main Menu Scene Loaded\n";
//    glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
//    glfwSetMouseButtonCallback(glfwGetCurrentContext(), mouseCallback);
//
//    glClearColor(0.2f, 0.5f, 0.2f, 1.0f);
//
//    shader = new Shader("G:/Projetos/Engine/DragonRage/DragonRage/shaders/button_vec_shader.glsl",
//        "G:/Projetos/Engine/DragonRage/DragonRage/shaders/button_frag_shader.glsl");
//
//    float buttonVertices[] = {
//        playBtn.x - playBtn.width, playBtn.y - playBtn.height,  // Bottom-left
//        playBtn.x + playBtn.width, playBtn.y - playBtn.height,  // Bottom-right
//        playBtn.x + playBtn.width, playBtn.y + playBtn.height,  // Top-right
//        playBtn.x - playBtn.width, playBtn.y + playBtn.height   // Top-left
//    };
//
//    unsigned int indices[] = {
//        0, 1, 2,  // First triangle
//        2, 3, 0   // Second triangle
//    };
//
//    // Generate buffers
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//
//    // Bind and set VBO and set EBO
//    glBindVertexArray(VAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(buttonVertices), buttonVertices, GL_STATIC_DRAW);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    // Define vertex attribute
//    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    // Unbind VAO and buffers
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//}
//
//
//void MainMenuScene::update(float dt) {}
//
//void MainMenuScene::render() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    shader->use();
//    shader->setVec3("color", glm::vec3(playBtn.r, playBtn.g, playBtn.b));
//    glm::mat4 projection = glm::ortho(0.0f, 1000.0f, 800.0f, 0.0f);
//    shader->setMat4("projection", projection);
//
//    glBindVertexArray(VAO);
//
//    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//    glBindVertexArray(0);
//}
//
//
//void MainMenuScene::unload() {
//    std::cout << "Main Menu Scene Unloaded\n";
//    glfwSetMouseButtonCallback(glfwGetCurrentContext(), NULL);
//
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteBuffers(1, &EBO);
//}
//
//void MainMenuScene::mouseCallback(GLFWwindow* window, int button, int action, int mods) {
//    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
//        double xpos, ypos;
//        glfwGetCursorPos(window, &xpos, &ypos);
//
//        if (xpos >= playBtn.x - playBtn.width || xpos <= playBtn.x + playBtn.width &&
//            ypos >= playBtn.y - playBtn.height || ypos <= playBtn.y + playBtn.height) {
//            SceneManager* sm = static_cast<SceneManager*>(glfwGetWindowUserPointer(window));
//            if (sm) {
//                sm->setScene(new FirstScene(*sm));
//            }
//        }
//    }
//}