#include "Window.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	Window* CreateWindow(int width, int height, const char *title);
	void SwapBuffers(Window*);
	void SetClearColor(float r, float g, float b, float a);
	void ClearScreen();
};

