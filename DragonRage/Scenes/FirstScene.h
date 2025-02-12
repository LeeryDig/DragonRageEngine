#pragma once
#ifndef FIRST_SCENE_H
#define FIRST_SCENE_H

#include "../input/camera.h"
#include "../src/Scene.h"
#include "../src/SceneManager.h"
#include "../shaders/Shader.h"
#include "../input/InputHandler.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

class FirstScene : public Scene {
public:
    FirstScene(SceneManager& manager);

    void load() override;
    void update(float dt) override;
    void render() override;
    void unload() override;

private:
    SceneManager&                 sceneManager;
    Shader*                             shader;
    unsigned int                 VAO, VBO, EBO;    
};

#endif
