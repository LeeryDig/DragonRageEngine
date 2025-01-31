#pragma once
#ifndef MAIN_MENU_SCENE_H
#define MAIN_MENU_SCENE_H

#include "../src/Scene.h"
#include "../src/SceneManager.h"
#include "FirstScene.h"
#include <GLFW/glfw3.h>
#include <iostream>

struct Button {
    float x, y, width, height;
    const char* text;
};

class MainMenuScene : public Scene {
public:
    MainMenuScene(SceneManager& manager) : sceneManager(manager) {}

    void                              load() override;
    void                    update(float dt) override;
    void                            render() override;
    void                            unload() override;
    void initializeInput(GLFWwindow* window) override;

private:
    SceneManager&                                                      sceneManager;
    static Button                                                        playButton;
    static void mouseCallback(GLFWwindow* window, int button, int action, int mods);
};


#endif
