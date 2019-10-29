#include "Renderer.h"

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

Window* Renderer::CreateWindow(int width, int height, const char *title)
{
	Window* w = new Window(width,height,title);
	return w;
}

void Renderer::SwapBuffers(Window* window)
{
	glfwSwapBuffers(window->GetWindow());
}

void Renderer::SetClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void Renderer::ClearScreen() {
	glClear(GL_COLOR_BUFFER_BIT);
}
