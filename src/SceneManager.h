#pragma once
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"
#include <memory>

class SceneManager {
public:
	SceneManager(GLFWwindow* window) : window(window) {}

	void setScene(Scene* newScene) {
		if (currentScene) {
			currentScene->unload();
			delete currentScene;
		}
		currentScene = newScene;

		if (currentScene) {
			currentScene->load();
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
	Scene*		currentScene;
	GLFWwindow*		  window;
};

#endif
