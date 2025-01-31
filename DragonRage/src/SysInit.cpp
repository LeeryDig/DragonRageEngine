
#include "../window/WindowManager.h"
#include "SysState.H"
#include "SceneManager.h"
#include "../Scenes/MainMenuScene.h"
#include <chrono>


const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 800;

int main() {
	WindowManager window(SCR_WIDTH, SCR_HEIGHT, "NICE GRAPHICS");
	SceneManager sceneManager(window.window);
	SysState systemState = SysState::MENU;

	sceneManager.setScene(std::make_unique<MainMenuScene>(sceneManager));
	auto lastTime = std::chrono::high_resolution_clock::now();

	while (!window.ShouldClose()) {
		auto now = std::chrono::high_resolution_clock::now();
		float deltaTime = std::chrono::duration<float>(now - lastTime).count();
		lastTime = now;

		sceneManager.update(deltaTime);
		sceneManager.render();

		window.SwapBuffers();
		window.PollEvents();
	}

	return 0;
}