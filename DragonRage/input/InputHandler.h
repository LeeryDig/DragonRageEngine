#pragma once
#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <GLFW/glfw3.h>
#include "../src/SysState.H"

void ProcessInputEditor(GLFWwindow* window, SysState& sysState);
void ProcessInputGame(GLFWwindow* window);

#endif
