#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <GLFW/glfw3.h>

class Scene {
public:
    virtual                         ~Scene() = default;

    virtual void                            load() = 0;
    virtual void                  update(float dt) = 0;
    virtual void                          render() = 0;
    virtual void                          unload() = 0;
    virtual void initializeInput(GLFWwindow* window) {}
};

#endif
