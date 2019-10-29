#include "Window.h"
#include "Renderer.h"
#define QP_API _declspec(dllexport)
class QP_API GameBase
{
private:
	Window *_window;
	Renderer *_rend;
public:
	GameBase();
	~GameBase();
	void GameLoop();
};

