#pragma once
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"
#include <memory>

class SceneManager {
public:
	SceneManager(GLFWwindow* window) : window(window) {}

	void setScene(std::unique_ptr<Scene> newScene) {
		if (currentScene) {
			currentScene->unload();
		}
		currentScene = std::move(newScene);
		if (currentScene) {
			currentScene->load();
			currentScene->initializeInput(window);
		}

		glfwSetWindowUserPointer(window, this);
	}

	void update(float dt) {
		if (currentScene) {
			currentScene->update(dt);
		}
	}

	void render() {
		if (currentScene) {
			currentScene->render();
		}
	}

private:
	std::unique_ptr<Scene> currentScene;
	GLFWwindow*					 window;
};

#endif
