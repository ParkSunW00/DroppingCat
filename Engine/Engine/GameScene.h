#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Animation.h"
#include "MainScene.h"
#include "Player.h"
#include "Background.h"
#include "Engine.h"
#include "Ball.h"
#include <list>

class GameScene : public Scene
{
private :

	std::list<Background*> backgroundList;
	std::list<Sprite*> floarList;
	std::list<Sprite*> obstacleList;
	std::list<Sprite*> ballList;
	std::list<Sprite*> engineList;
	std::list<Sprite*> goalList;
	std::list<Sprite*> optionList;

	Player* player;
    Engine* engine;
	Ball* ball;

public :
	GameScene();
	~GameScene();

	Sprite* clickButton;

	Sprite* returnButton;
	Sprite* optionButton;
	Sprite* homeButton;

	void Render();
	void Update(float dTime);
};