#include "GameBase.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

GameBase::GameBase()
{
	glfwInit();
	_window = new Window(800,600,"Yo!");
	glfwSetFramebufferSizeCallback(_window->GetWindow(), framebuffer_size_callback);

	GameLoop();
}


GameBase::~GameBase()
{
}

void GameBase::GameLoop()
{
	while (!glfwWindowShouldClose(_window->GetWindow()))
	{
		glfwSwapBuffers(_window->GetWindow());
		SetClearColor(0.5, 0, 0.2, 1);				//Esto deberia llamarse desde Game
		glClear(GL_COLOR_BUFFER_BIT);				//Limpia la pantalla del ultimo color asignado (Negro por defecto)
		glfwPollEvents();
	}

	glfwTerminate();
}

void GameBase::SetClearColor(float r, float g, float b, float a) {
	glClearColor(r, g, b, a);
}
