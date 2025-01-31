#pragma once
#ifndef FIRST_SCENE_H
#define FIRST_SCENE_H

#include "../src/Scene.h"
#include "../src/SceneManager.h"

class FirstScene : public Scene {
public:
    FirstScene(SceneManager& manager) : sceneManager(manager) {}

    void                              load() override;
    void                    update(float dt) override;
    void                            render() override;
    void                            unload() override;
    void initializeInput(GLFWwindow* window) override;

private:
    SceneManager&                                                      sceneManager;
    static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
};

#endif
