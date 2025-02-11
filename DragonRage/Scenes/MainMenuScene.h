#pragma once
#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

#include "../src/Scene.h"
#include "../src/SceneManager.h"
#include "../shaders/Shader.h"
#include "FirstScene.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

struct Button {
    float x, y, width, height;
    float r, g, b;
    const char* text;
};

class MainMenuScene : public Scene {
public:
    MainMenuScene(SceneManager& manager);

    void load() override;
    void update(float dt) override;
    void render() override;
    void unload() override;

private:
    SceneManager&                                                      sceneManager;
    Shader*                                                                  shader;
    static Button                                                           playBtn;
    static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
    unsigned int                                                      VAO, VBO, EBO;
};


#endif
