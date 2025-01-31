#pragma once
#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

class WindowManager {
public:
    WindowManager(int width, int height, const char* title);
    ~WindowManager();

    bool ShouldClose() const;
    void PollEvents();
    void SwapBuffers();
    GLFWwindow* window;

private:
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif


