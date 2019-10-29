#pragma once
#include "Window.h"
#define QP_API _declspec(dllexport)
class QP_API GameBase
{
private:
	Window *_window;
public:
	GameBase();
	~GameBase();
	void GameLoop();
protected:
	void SetClearColor(float r, float g, float b, float a);
};

