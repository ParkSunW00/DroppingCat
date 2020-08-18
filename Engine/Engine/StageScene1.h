#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "GameScene.h"
#include <list>

class StageScene1 : public Scene
{
private:
	std::list<Sprite*>collectboxList;
public:
	StageScene1();
	~StageScene1();

	Sprite* background;
	Sprite* formerButton;

	Sprite* glass;

	void Render();
	void Update(float dTime);


};

