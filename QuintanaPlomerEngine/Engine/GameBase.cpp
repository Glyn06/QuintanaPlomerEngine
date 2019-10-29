#include "GameBase.h"
#include <iostream>

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
	while (!glfwWindowShouldClose(_window->GetWindow())) {
		glfwSwapBuffers(_window->GetWindow());
		glfwPollEvents();
	}
}
