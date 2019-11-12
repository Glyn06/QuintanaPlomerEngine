#include "Renderer.h"

#include "glew.h"
#include "glfw3.h"
#include "GameBase.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }
Window *_window;
Renderer *_rend;
GameBase::GameBase()
{
	
	if(!glfwInit())
	{ 
		printf("glfw error");
	}
		
	
	_window = _rend->CreateWindow(800, 600, "Yo!");		//Esto deberia llamarse desde Game
	glfwSetFramebufferSizeCallback(_window->GetWindow(), framebuffer_size_callback);
	_rend = new Renderer();
	

	Init();
	printf("did init");
	//init
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
		//llama a los metodos virtuales, el exe se encarga de la logica
		
		Update();

		_rend->SwapBuffers(_window);
		_rend->SetClearColor(0.0f, 0.0f, 0.2f, 1.0f);		//Esto deberia llamarse desde Game
		_rend->ClearScreen();						//Limpia la pantalla del ultimo color asignado (Negro por defecto)
		glfwPollEvents();
	}

	glfwTerminate();
}
