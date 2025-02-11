#include <iostream>
#include "InputHandler.h"

void ProcessInputEditor(GLFWwindow* window, SysState& sysState) {
	if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS) {
		sysState = SysState::EDITOR;
	}

	if (glfwGetKey(window, GLFW_KEY_F2) == GLFW_PRESS) {
		sysState = SysState::MENU;
	}

	if (glfwGetKey(window, GLFW_KEY_F3) == GLFW_PRESS) {
		sysState = SysState::PLAYING;
	}
}

void ProcessInputGame(GLFWwindow* window, float deltaTime, Camera& camera) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);

	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		camera.ProcessKeyboard(FORWARD, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		camera.ProcessKeyboard(LEFT, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		camera.ProcessKeyboard(RIGHT, deltaTime);
	}
	std::cout << "Camera Position: ("
		<< camera.Position.x << ", "
		<< camera.Position.y << ", "
		<< camera.Position.z << ")" << std::endl;
}
