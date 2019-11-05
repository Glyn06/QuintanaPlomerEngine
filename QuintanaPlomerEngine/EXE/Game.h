#ifndef GAME_H
#define GAME_H

#include "GameBase.h"
class Game : public GameBase
{
public:
	Game();
	void Init();	//no hace falta override 
	void Update();
	void DeInit();
	~Game();
};
#endif
