#ifndef GAMEBASE_H
#define GAMEBASE_H

//input
#include "Shape.h"
#include "Window.h"

#define QP_API _declspec(dllexport)//resuelve unresolved external simbol, para que pueda ser exportado (lo envia a la tabla de simbolos)
class GameBase
{
private:

public:
	QP_API virtual void Init() = 0;
	QP_API virtual void Update() = 0;
	QP_API virtual void DeInit() = 0;
	QP_API GameBase();
	QP_API ~GameBase();
	QP_API void GameLoop();

	// virtuals here, also protected, in the others h redeclare and override
	// init, update,  deinit virtuales en la dll y en el exe se overridean
};


#endif // !GAMEBASE_H
