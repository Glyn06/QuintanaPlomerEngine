#include "GameBase.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

GameBase::GameBase()
{
	glfwInit();
	_rend = new Renderer();
	_window = _rend->CreateWindow(800, 600, "Yo!");		//Esto deberia llamarse desde Game
	glfwSetFramebufferSizeCallback(_window->GetWindow(), framebuffer_size_callback);

	GameLoop();
}


GameBase::~GameBase()
{
	delete _window;
	delete _rend;
}

void GameBase::GameLoop()
{
	while (!glfwWindowShouldClose(_window->GetWindow()))
	{
		_rend->SwapBuffers(_window);
		_rend->SetClearColor(0, 0, 0.2, 1);		//Esto deberia llamarse desde Game
		_rend->ClearScreen();						//Limpia la pantalla del ultimo color asignado (Negro por defecto)
		glfwPollEvents();
	}

	glfwTerminate();
}
