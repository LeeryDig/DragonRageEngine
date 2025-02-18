
#include <chrono>

#include "SysState.H"
#include "SceneManager.h"
#include"ShaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"


const unsigned int SCR_WIDTH = 960;
const unsigned int SCR_HEIGHT = 540;

GLfloat vertices[] =
{
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
};

// Indices for vertices order
GLuint indices[] =
{
	0, 3, 5, // Lower left triangle
	3, 2, 4, // Lower right triangle
	5, 4, 1 // Upper triangle
};

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "NICE GRAPHICS", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, SCR_WIDTH, SCR_WIDTH);

	// -- SHADER LOADING -- //
	Shader shaderProgram("default.vert", "default.frag");

	// -- VERTEX BUFFER AND LINKING -- //
	VAO VAO1;
	VAO1.Bind();
	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));
	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// -- LOADING SCENE MANAGER -- //
	SceneManager sceneManager(window);
	//sceneManager.setScene(new MainMenuScene(sceneManager));

	// -- SYSTEM MANAGER -- //
	SysState systemState = SysState::MENU;
	
	auto lastTime = std::chrono::high_resolution_clock::now();

	// -- MAIN GAME LOOP -- //
	while (!glfwWindowShouldClose(window)) { 
		// -- TIME COUNTING -- //
		auto now = std::chrono::high_resolution_clock::now();
		float deltaTime = std::chrono::duration<float>(now - lastTime).count();
		lastTime = now;

		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// -- SHADER -- //
		shaderProgram.Activate();
		VAO1.Bind();

		// -- PHYSICS -- //
		sceneManager.update(deltaTime);

		// -- RENDER -- //
		sceneManager.render();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0); 

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}