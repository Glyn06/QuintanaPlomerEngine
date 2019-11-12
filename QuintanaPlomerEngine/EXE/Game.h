#ifndef GAME_H
#define GAME_H

//#include "entity"


#include "GameBase.h"
#include <iostream>
using namespace std;
class Game : public GameBase
{
private:
	//Shape* shape;
public:
	Game();
	void Init();
	void Update();
	void DeInit();
	~Game();
};
#endif
/*
engine
copy "$(OutDir)Engine.dll" "$(SolutionDir)bin\Win32" /y
copy "$(SolutionDir)libs\GLEW\dll\glew32.dll" "$(OutDir)" /y
game
copy "$(SolutionDir)libs\EngineDLL\lib\Win32\Engine.dll" "$(OutDir)" /y
copy "$(SolutionDir)libs\GLEW\dll\glew32.dll" "$(OutDir)" /y
*/