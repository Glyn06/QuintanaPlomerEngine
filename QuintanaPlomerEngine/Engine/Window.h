#pragma once
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
};

