#ifndef RENDERER_H
#define RENDERER_H

#include "glew.h"
#include "glfw3.h"
#include "Shape.h"
#include "Window.h"

class Renderer
{
private:
	unsigned int _buffer;
	float x;
	float y;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int VAO;
	Shape* shape;
	GLuint shaderProgram;
public:
	Renderer();
	~Renderer();
	Window* CreateWindow(int width, int height, const char *title);
	void SwapBuffers(Window*);
	void SetClearColor(float r, float g, float b, float a);
	void ClearScreen();
};
#endif
