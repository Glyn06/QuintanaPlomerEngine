#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
using namespace std;
#include "glfw3.h"

class Window
{
private:
	GLFWwindow* _w;
public:
	Window(int w, int h, const char *title);
	~Window();
	GLFWwindow* GetWindow() { return _w; };
};

#endif // !WINDOW_H

