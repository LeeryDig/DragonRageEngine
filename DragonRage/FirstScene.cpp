//#include "FirstScene.h"
//
//// Precisa melhorar e tirar essas variaveis daqui
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//
//int SCR_WIDTH;
//int SCR_HEIGHT;
//
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//bool firstMouse = true;
//
//FirstScene::FirstScene(SceneManager& manager)
//    : sceneManager(manager), VAO(0), VBO(0), EBO(0), shader(nullptr) {
//}
//
//void FirstScene::load() {
//    std::cout << "First Scene Loaded\n";
//    // Load assets, create objects, initialize game state
//    glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//    glfwGetFramebufferSize(glfwGetCurrentContext(), &SCR_WIDTH, &SCR_HEIGHT);
//
//    glEnable(GL_DEPTH_TEST);
//
//    glClearColor(0.1f, 0.5f, 0.8f, 1.0f);
//
//    shader = new Shader("shaders/cube_ver_shader.glsl", "shaders/cube_frag_shader.glsl");
//
//    float vertices[] = {
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//    };
//
//    // Generate buffers
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &this->VAO);
//    glGenBuffers(1, &this->VBO);
//
//    glBindVertexArray(this->VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    // position attribute
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    // texture coord attribute
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//}
//
//void FirstScene::update(float dt) {
//    // Update game objects, physics, input handling
//    ProcessInputGame(glfwGetCurrentContext(), dt, camera);
//    glfwSetCursorPosCallback(glfwGetCurrentContext(), mouse_callback);
//}
//
//void FirstScene::render() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    //Camera
//    shader->use();
//    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//    shader->setMat4("projection", projection);
//    glm::mat4 view = camera.GetViewMatrix();
//    shader->setMat4("view", view);
//
//    // world space positions of our cubes
//    glm::vec3 cubePositions[] = {
//        glm::vec3(0.0f,  0.0f,  0.0f),
//        glm::vec3(2.0f,  5.0f, -15.0f),
//        glm::vec3(-1.5f, -2.2f, -2.5f),
//        glm::vec3(-3.8f, -2.0f, -12.3f),
//        glm::vec3(2.4f, -0.4f, -3.5f),
//        glm::vec3(-1.7f,  3.0f, -7.5f),
//        glm::vec3(1.3f, -2.0f, -2.5f),
//        glm::vec3(1.5f,  2.0f, -2.5f),
//        glm::vec3(1.5f,  0.2f, -1.5f),
//        glm::vec3(-1.3f,  1.0f, -1.5f)
//    };
//
//    glBindVertexArray(this->VAO);
//    for (unsigned int i = 0; i < 10; i++)
//    {
//        glm::mat4 model = glm::mat4(1.0f);
//        model = glm::translate(model, cubePositions[i]);
//        float angle = 20.0f * i;
//        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//        shader -> setMat4("model", model);
//
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//    }
//
//}
//
//void FirstScene::unload() {
//    std::cout << "First Scene Unloaded\n";
//    // Cleanup memory, remove game objects
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteBuffers(1, &EBO);
//}
//
//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
//    float xpos = static_cast<float>(xposIn);
//    float ypos = static_cast<float>(yposIn);
//
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos;
//
//    lastX = xpos;
//    lastY = ypos;
//
//    camera.ProcessMouseMovement(xoffset, yoffset);
//}