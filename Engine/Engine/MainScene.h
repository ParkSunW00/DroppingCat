#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "GameScene.h"
#include <list>

class MainScene : public Scene
{
private:
	std::list<Sprite*>startList;
public :
	MainScene();
	~MainScene();

	Sprite* background;
	Sprite* exitButton;
	Sprite* title;

	void Render();
	void Update(float dTime);
};