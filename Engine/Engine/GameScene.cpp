#include "stdafx.h"
#include "ClearScene.h"
#include "GameScene.h"

GameScene::GameScene() {

	//BACKGROUND
	Background *background = new Background();
	background->setPos(0, 0);
	backgroundList.push_back(background);
	AddObject(background);

	//FLOAR
	Sprite* tmpFloar = new Sprite("Resource/floar2.png");
	tmpFloar->setPos(0, 600);
	floarList.push_back(tmpFloar);

	//OPTION -> RETURN-BTN
	returnButton = new Sprite("Resource/return.png");
	AddObject(returnButton);
	returnButton->setPos(1100, 70);

	//OPTION -> OPTION-BTN
	optionButton = new Sprite("Resource/option.png");
	AddObject(optionButton);
	optionButton->setPos(1230, 70);

	//OPTION -> HOME-BTN
	homeButton = new Sprite("Resource/home.png");
	AddObject(homeButton);
	homeButton->setPos(1370, 70);

	//CLICK-BTN
	clickButton = new Sprite("Resource/click-btn.png");
	AddObject(clickButton);
	clickButton->setPos(1250, 650);

	//GOAL
	Sprite* tmpGoal = new Sprite("Resource/goal.png");
	tmpGoal->setPos(1200, 327);
	goalList.push_back(tmpGoal);

	//OBSTACLE
	Sprite* tmpObstacle = new Sprite("Resource/attrition.png");
	tmpObstacle->setPos(500,600);
	obstacleList.push_back(tmpObstacle);

	//ENGINE
	Sprite* tmpEngine_txt = new Sprite("Resource/Egn.png");
	tmpEngine_txt->setPos(50, 90);
	engineList.push_back(tmpEngine_txt);

	//BALL
	ball = new Ball();
	ball->setPos(250, 520);

	//PLAYER
	player = new Player();
	player->setPos(70,330);

	//ENGINE
	engine = new Engine();
	engine->setPos(350, 90);
}

GameScene::~GameScene() {

}

void GameScene::Render() {
	
	//BACKGROUND
	for (auto& background : backgroundList) {
		background->Render();
	}

	//FLOAR
	for (auto& floar : floarList) {
		floar->Render();
	}

	//OBSTACLE
	for (auto& obstacle : obstacleList) {
		obstacle->Render();
	}

	//GOAL
	for (auto& goal : goalList) {
		goal->Render();
	}

	//OPTION
	for (auto& option : optionList) {
		option->Render();
	}

	//ENGINE TXT
	for (auto& engine_txt : engineList) {
		engine_txt->Render();
	}

	//ENGINE
	engine->Render();

	//PLAYER
	player->Render();

	//CLICK-BTN
	clickButton->Render();

	//OPTION -> RETURN-BTN
	returnButton->Render();

	//OPTION -> OPTION-BTN
	optionButton->Render();

	//OPTION -> HOME-BTN
	homeButton->Render();

	//BALL
	ball->Render();
}

void GameScene::Update(float dTime) {
	Scene::Update(dTime);
	player->Update(dTime);
	engine->Update(dTime);
	ball->Update(dTime);

	//CLICK-BTN
	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {
		if (clickButton->IsPointInRect(inputManager->GetMousePos())) {
			player->setIsClicked(!player->getIsClicked());
		}
	}

	//ENGINE
	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {
		if (clickButton->IsPointInRect(inputManager->GetMousePos())) {
			engine->setIsClicked(!engine->getIsClicked());
		}
	}

	//BALL
	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {
		if (clickButton->IsPointInRect(inputManager->GetMousePos())) {
			ball->setIsClicked(!ball->getIsClicked());
		}
	} 

	//BACKGROUND
	for (auto& background : backgroundList) {
		background->Update(dTime);
	}
	
	//FLOAR
	for (auto& floar : floarList) {
		floar->Update(dTime);
	}

	//OPTION-BTN
	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) {

		if (returnButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new GameScene());
			return;
		}

		if (optionButton->IsPointInRect(inputManager->GetMousePos())) {
			return;
		}
		if (homeButton->IsPointInRect(inputManager->GetMousePos())) {
			sceneManager->ChangeScene(new MainScene());
		}
	}

	//GOAL
	for (auto iter = goalList.begin(); iter != goalList.end(); iter++) {
		if (ball->IsCollisionRect(*iter)) {
			sceneManager->ChangeScene(new ClearScene);
			return;
		}
	} 

}