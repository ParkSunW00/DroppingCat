#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "MainScene.h"
#include "Background.h"
#include <list>

class ClearScene : public Scene
{
private:
	std::list<Sprite*> collectList;
	std::list<Sprite*> goalList;
	std::list<Sprite*> optionList;

public:
	ClearScene();
	~ClearScene();

	Sprite* background;
	Sprite* clear_txt;

	Sprite* returnButton;
	Sprite* optionButton;
	Sprite* homeButton;

	void Render();
	void Update(float dTime);
};

