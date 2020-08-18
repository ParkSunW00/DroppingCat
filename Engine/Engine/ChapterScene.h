#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "GameScene.h"
#include <list>

class ChapterScene : public Scene
{
private:
public:
	ChapterScene();
	~ChapterScene();

	Sprite* background;
	Sprite* chapter1;
	Sprite* chapter2;
	Sprite* chapter3;

	Sprite* formerButton;

	void Render();
	void Update(float dTime);
};

