#ifndef GAMEBASE_H
#define GAMEBASE_H

//input
#include "Shape.h"
#include "Window.h"

#define QP_API _declspec(dllexport)
class QP_API GameBase
{
private:

protected:
	virtual void Init()=0;
	virtual void Update()=0;
	virtual void DeInit()=0;
public:
	GameBase();
	~GameBase();
	void GameLoop();

	// virtuals here, also protected, in the others h redeclare and override
	// init, update,  deinit virtuales en la dll y en el exe se overridean
};


#endif // !GAMEBASE_H
