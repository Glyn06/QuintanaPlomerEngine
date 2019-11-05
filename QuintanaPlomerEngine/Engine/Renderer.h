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
	Shape* shape;

	GLuint shaderProgram;
public:
	Renderer();
	~Renderer();
	void Bind(float _vertex[], int _index[], int _arraySize);
	void LoadShaders(float _vertex []);
	Window* CreateWindow(int width, int height, const char *title);
	void SwapBuffers(Window*);
	void SetClearColor(float r, float g, float b, float a);
	void ClearScreen();
};
#endif
