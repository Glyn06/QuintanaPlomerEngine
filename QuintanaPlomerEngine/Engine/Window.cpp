#include "Window.h"



Window::Window(int width, int height, const char *title)
{
	_w = glfwCreateWindow(width, height, title, NULL, NULL);
	if (_w == NULL)
	{
		cout << "Failed to create window" << endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(_w);
}


Window::~Window()
{
}
